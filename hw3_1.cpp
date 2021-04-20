/*
 * Title: hw3_1.cpp
 * Abstract: This program takes in two words form a user and checks whether they are anagrams of eachother.
 * Author: Bryan Hernandez
 * ID: 0711
 * Date: 02/19/21
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void print(map<char, int> vals){
    for (auto itr = vals.begin(); itr != vals.end(); ++itr)
        cout << itr->first << ": " << itr->second << '\n';
}

int main (){
    
    string str1, str2;
    map<char, int> vals;
    
    cin >> str1;
    cin >> str2;
    
    if(str1.length() != str2.length()){
        cout << "NO ANAGRAM";
        return 0;
    }
    
    for(int i = 0; i < str1.length(); i++){
        vals.insert({str1[i], 0});
    }
        
    for(int i = 0; i < str2.length(); i++){
        if(vals.find(str2[i]) != vals.end())
            vals.at(str2[i]) = vals.at(str2[i]) + 1;
    }
    
   for (auto const [k, v] : vals){
       if(v == 0){
           cout << "NO ANAGRAM";
           return 0;
       }
   }
   
    cout << "ANAGRAM" << endl;
    print(vals);
}