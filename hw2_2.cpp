/*
 * Title: hw2_2.cpp
 * Abstract: This program shows a version of the power set program that Dr Byun gave us.
 * Author: Bryan Hernandez
 * ID: 0711
 * Date: 02/12/21
 */
 
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void printPowerSet(vector <string> set, int set_size) {
    /*set_size of power set of a set with set_size 
    n is (2**n -1)*/
    if(set_size == 0){
        cout << "0:EMPTY" << endl;
        return;
    }

    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;

    /*Run from counter 000..0 to 111..1*/
    for (counter = 0; counter < pow_set_size; counter++) {
        int bin[set_size];
        int count = 0;
        
        for (j = 0; j < set_size; j++) {
            /* Check if jth bit in the counter is set 
              If set then print jth element from set */
              if (counter & (1 << j)) {
                  bin[j] = 1;
                  count++;
              } else {
                  bin[j] = 0;
                  count++;
              }
        }
        
        for (int i = set_size - 1; i >= 0; i--)
            cout << bin[i];
        cout << ":";
        
        bool isZero = true;
        
        for (int i = set_size - 1; i >= 0; i--) {
            if (bin[i] == 1) {
                cout << set[i] << " ";
                isZero = false;
            }
        }
        
        if (isZero)
            cout << "EMPTY";
        cout << endl;
        }
}
    
int main() {
    int s;
    vector<string> userInput;
    
    cin >> s;
    for (int i = 0; i < s; i++) {
        string temp;
        cin >> temp;
        userInput.insert(userInput.begin(), temp);
    }
    
    printPowerSet(userInput, s);
    return 0;
} // This code is contributed by SoM15242 