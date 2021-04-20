/*
 * Title: hw4_1.cpp
 * Abstract: This program dipslays the best combination of a knapsack
 * Author: Bryan Hernandez
 * ID: 0711
 * Date: 02/26/21
 */
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int max(int a, int b) { 
    return (a > b) ? a : b; 
}
 
void bestCombo(int k_capacity, int cap[], int val[], int n) 
{ 
    int i, c; 
    int K[n + 1][k_capacity + 1]; 
    
    for (i = 0; i <= n; i++) { 
        for (c = 0; c <= k_capacity; c++) { 
            if (i == 0 || c == 0) 
                K[i][c] = 0; 
            else if (cap[i - 1] <= c) 
                K[i][c] = max(val[i - 1] +  
                    K[i - 1][c - cap[i - 1]], K[i - 1][c]); 
            else
                K[i][c] = K[i - 1][c]; 
        } 
    } 
    
    int res = K[n][k_capacity];
    int value = res;
    
    c = k_capacity; 
    int sum = 0;
    vector<int> indexes;
    for (i = n; i > 0 && res > 0; i--) { 
        if (res == K[i - 1][c])
            continue;  
        else { 
            sum += cap[i - 1];
            res = res - val[i - 1]; 
            c = c - cap[i - 1]; 
            indexes.push_back(i);
        } 
    } 
    
    sort(indexes.begin(), indexes.end());
    
    cout << "Item:";
    for(int i = 0; i < indexes.size(); i++)
        cout << indexes[i] << " ";
    cout << endl << "Capacity:" << sum << endl;
    cout << "Value:" << value;
} 
 
int main(){
    int k_items, k_capacity;
    cin >> k_items >> k_capacity;
    
    int val[k_items] = {};
    int cap[k_items] = {};
    for(int i = 0; i < k_items; i++){
        int temp_cap, temp_val;
        cin >> temp_cap >> temp_val;
        
        val[i] = temp_val;
        cap[i] = temp_cap;
    }
    int n = sizeof(val) / sizeof(val[0]);
    bestCombo(k_capacity, cap, val, n);
}