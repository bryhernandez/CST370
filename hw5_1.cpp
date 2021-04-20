/*
 * Title: hw5_1.cpp
 * Abstract: This program dipslays whether two words are palindromes recursively
 * Author: Bryan Hernandez
 * ID: 0711
 * Date: 03/05/21
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string palindrome(string temp, string str, int size){
    if(size == 0){
        return temp;
    } else{
        temp += str[size-1];
        return palindrome(temp, str, size-1);
    }
}

int main(){
    string str = "";
    getline(cin, str);
    
    for(int i = 32; i <= 47; i++){ // this will remove all the unecessary char
        str.erase(remove(str.begin(), str.end(), i), str.end() );
    }
    
    for(int i = 58; i <= 64; i++){ // this will remove all the unecessary char
        str.erase(remove(str.begin(), str.end(), i), str.end() );
    }
    
    for(int i = 91; i <= 96; i++){ // this will remove all the unecessary char
        str.erase(remove(str.begin(), str.end(), i), str.end() );
    }
    
    for(int i = 123; i <= 126; i++){ // this will remove all the unecessary char
        str.erase(remove(str.begin(), str.end(), i), str.end() );
    }
    
    transform(str.begin(), str.end(), str.begin(), ::tolower); //makes all the letters to lower case
    
    string temp = "";
    string pal = palindrome(temp, str, str.size());
    
    if(pal == str)
        cout << "TRUE";
    else
        cout << "FALSE";
}