#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <omp.h>
using namespace std;
using namespace chrono;

// Predefined knapsack capacity
const int W = 50000;
int P, L = 0;

// Global time points
time_point<high_resolution_clock> vectorBuildStart, vectorBuildEnd;
time_point<high_resolution_clock> storeResultStart, storeResultEnd;
time_point<high_resolution_clock> itemPrintStart, itemPrintEnd;
time_point<high_resolution_clock> fileReadingStart, fileReadingEnd;
time_point<high_resolution_clock> knapsackExecutionStart, knapsackExecutionEnd;
time_point<high_resolution_clock> knapsackExecutionCallStart, knapsackExecutionCallEnd;
time_point<high_resolution_clock> executionTotalStart, executionTotalEnd;

// Function to solve the knapsack problem
void knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
    
    knapsackExecutionStart = high_resolution_clock::now();

    vectorBuildStart = high_resolution_clock::now();

    // Create a 2D vector to store results of subproblems
    vector<vector<int>> K(n + 1, vector<int>(W + 1, 0));
    // Build table K[][] in bottom-up manner
    
    for (int i = 0; i <= n; i++) {
        #pragma omp parallel for num_threads(8) 
        for (int w = 0; w <= W; w++) {
            
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            }
            else if (wt[i - 1] <= w) { // Item can be part of the solution
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]); 
                P++;
            }
            else { // wt[i-1] > w
                K[i][w] = K[i - 1][w];
                L++;
            }
            
        }
    }
    vectorBuildEnd = high_resolution_clock::now();

    storeResultStart = high_resolution_clock::now();
    // Store the result of Knapsack
    int res = K[n][W];
    cout << "Maximum price to be included in the container with capacity " << W << " kg: " << res << "$\n";
    
    storeResultEnd = high_resolution_clock::now();

    itemPrintStart = high_resolution_clock::now();
    int w = W;
    cout << "Items included in the container: \n";
    
 
    
    for (int i = n; i > 0; i--) {
        if(res>0){
        // If the result came from K[i-1][w], it means the item was not included
        if (res != K[i - 1][w]) {
            cout << "item #" << i << " with weight of: " << wt[i - 1] << " kg\n";   
            // Since this weight is included, subtract its value and weight
            res = res - val[i - 1];
            w = w - wt[i - 1]; 
        } 
        }

    }

    cout << "P = " << P << " L =  " << L << "\n";


    itemPrintEnd = high_resolution_clock::now();
    knapsackExecutionEnd = high_resolution_clock::now();
    
}

int main() {

    // Start measuring time
    executionTotalStart = high_resolution_clock::now();
    
    vector<int> wt;  // Vector to store item weights
    vector<int> val; // Vector to store item values
    int n = 0;       // Number of items

    fileReadingStart = high_resolution_clock::now();

    string filename = "knapsack_items_large.csv"; 
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return 1;
    }

    // Read the header line
    string header;
    getline(inputFile, header);

    // Read weights and values from the file
    string line;
    int weight, price;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string item; // To hold the item name
        string priceStr, weightStr;

        // Read item name, price, and weight from the line
        getline(ss, item, ',');      // Read item name (ignored)
        getline(ss, priceStr, ',');  // Read price as string
        getline(ss, weightStr, ','); // Read weight as string

        // Convert price and weight strings to integers
        try {
            price = stoi(priceStr);
            weight = stoi(weightStr);
        } catch (const invalid_argument& e) {
            cout << "Error: Could not convert price or weight to an integer.\n";
            continue;
        }

        // Store the price as value and weight
        val.push_back(price);
        wt.push_back(weight);
        n++;
    }

    inputFile.close(); // Close the file
    fileReadingEnd = high_resolution_clock::now();

    knapsackExecutionCallStart = high_resolution_clock::now();
    // Call knapsack function
    knapSack(W, wt, val, n);
    // End measuring time
    knapsackExecutionCallEnd = high_resolution_clock::now();
    executionTotalEnd = high_resolution_clock::now();

    // Calculate durations
    duration<double> fileReading = fileReadingEnd - fileReadingStart;
    duration<double> vectorBuild = vectorBuildEnd - vectorBuildStart;
    duration<double> storeResult = storeResultEnd - storeResultStart;
    duration<double> itemPrint = itemPrintEnd - itemPrintStart;
    duration<double> knapsackExecution = knapsackExecutionEnd - knapsackExecutionStart;
    duration<double> knapsackExecutionCall = knapsackExecutionCallEnd - knapsackExecutionCallStart;
    duration<double> executionTotal = executionTotalEnd - executionTotalStart;
    
    // Display the execution times
    cout << "\nTotal execution time: " << executionTotal.count() << " sec\n";
    cout << "\nExecution time for the knapsack function (Including the function call): " << knapsackExecutionCall.count() << " sec\n";
    cout << "\nExecution time for the knapsack function: " << knapsackExecution.count() << " sec\n";
    cout << "\nExecution time for the 1st section of the knapsack (Knapsack table construction): " << vectorBuild.count() << " sec\n";
    cout << "\nExecution time for the 2nd section of the knapsack (Storing and printing the maximum price): " << storeResult.count() << " sec\n";
    cout << "\nExecution time for the 3rd section of the knapsack (Backtracking to find items): " << itemPrint.count() << " sec\n";
    cout << "\nExecution time for file reading and parsing: " << fileReading.count() << " sec\n";
    
    return 0;
}
