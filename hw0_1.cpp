/*
 * Title: hw0_1.cpp
 * Abstract: This program red users input and does either a sum or difference command depending on the key the uer inputs.
 * Author: Bryan Hernandez
 * ID: 0711
 * Date: 01/28/2021
 */

#include <iostream>
#include <cmath>
using namespace std;

int sum(int num1, int num2){
    int sum = num1+ num2;
    
    return sum;
}

int diff(int num1, int num2){
    int diff = num1 - num2;
    
    return abs(diff);
}

int main(){
    
    int option, num1, num2, answer;
    
    cin >> option;
    
    while(option != 9){
        cin >> num1;
        cin >> num2;
        
        if(option == 1)
            answer = sum(num1, num2);
        else if(option == 2)
            answer = diff(num1, num2);
        else if(option == 9)
            exit;
            
        cout << answer << endl;
        cin >> option;
    }
}