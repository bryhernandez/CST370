/*
 * Title: hw1_1.cpp
 * Abstract: This program takes multiple numbers from user and then determines which numbers were repeated the most and how many times.
 * Author: Bryan Hernandez
 * ID: 0711
 * Date: 02/05/21
 */

#include <iostream>
#include <vector>
using namespace std;

int numDup(int arr[], int dup, int size){ //will find the number of times that dup is in the arr
    int count = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == dup)
            count ++;
    }
    
    return count;
}

int main(){
   int n, m;
   
   cin >> n;
   int list[n];
   
   for(int i = 0; i < n; i ++){ //inputs the user inputs into an array
       cin >> m;
       list[i] = m;
   }
   
   int max = 0, dupNum;
   for(int i = 0; i < n; i ++){
       if(numDup(list, list[i], n) >= max){ 
           if(numDup(list, list[i], n) == max){
               if(dupNum < list[i]){ // this should make it so that the larger number is the answer
                   dupNum = list[i];
               }
           } else {
               max = numDup(list, list[i], n);
               dupNum = list[i];
           }
       }
   }
   
   cout << "Number: " << dupNum << endl <<
   "Frequency: " << max;
   
}