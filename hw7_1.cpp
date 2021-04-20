/*
 * Title: hw7_1.cpp
 * Abstract: this program will display the biggest number ina list but with the divide and conquer method
 * Author: Bryan Hernandez
 * ID: 0711
 * Date: 03/26/2021
 */

#include <iostream>
using namespace std;

int find_max(int arr[], int start, int end) {
  if (start == end)
    return arr[start];
  else {
    int num1 = find_max(arr, start, (start + end) / 2);
    int num2 = find_max(arr, (start + end) / 2 + 1, end);
    if(num1 > num2)
      return num1;
    else
      return num2;
  }
}

int main (){
    int n;
    
    cin >> n;
    
    int arr[n];
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << find_max(arr, 0, n-1);
}