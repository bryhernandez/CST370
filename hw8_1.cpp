/*
 * Title: hw8_1.cpp
 * Abstract: this program will take in a int number adn reverse gettign rid of the leading zeros
 * Author: Bryan Hernandez
 * ID: 0711
 * Date: 04/09/21
 */

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<char> flip(vector<char> reverse){
    vector<char> flipped;
    for (int i = reverse.size()-1; i >= 0; i --){
        if(reverse[i] != '0')
            flipped.push_back(reverse[i]);
    }
    
    return flipped;
}

int main(){
    string num;
    cin >> num;
    
    vector<char> reverse;
    for(int i = 0; i < num.length(); i ++){
        reverse.push_back(num[i]);
    }
    
    vector<char> flipped = flip(reverse);
    
    for(int i = 0; i < flipped.size(); i++){
        cout << flipped[i];
    }
    
}
