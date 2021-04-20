/*
 * Title: hw1_2.cpp
 * Abstract: This program identifies the numbers that are not present in both lists. 
 * Author: Bryan Hernandez
 * ID: 0711
 * Date: 02/05/21
 */
 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool commonNums(int arr1[], int num, int size){
    
    for(int i = 0; i < size; i ++){
        if(arr1[i] == num)
            return true;
    }
    
    return false;
}

int main(){
    int size1, size2, n;
    
    cin >> size1;
    int arr1[size1];
    
    for(int i = 0; i < size1; i++){
        cin >> n;
        arr1[i] = n;
    }
    
    cin >> size2;
    int arr2[size2];
    
    for (int i = 0; i < size2; i ++){
        cin >> n;
        arr2[i] = n;
    }
    
    vector<int> uncommons;
    
    for(int i = 0; i < size1; i++){
        if(!commonNums(arr2, arr1[i], size2)){
            uncommons.push_back(arr1[i]);
        }
    }
    
    for(int i = 0; i < size2; i++){
        if(!commonNums(arr1, arr2[i], size1)){
            uncommons.push_back(arr2[i]);
        }
    }
    
    sort(uncommons.begin(), uncommons.end());
    
    if(!uncommons.size())
        cout << "Answer:NONE";
    else{
        cout << "Answer:";
        for(int i = uncommons.size()-1; i >= 0; i--){
            cout << uncommons[i] << " "; 
        }
    }
    
}