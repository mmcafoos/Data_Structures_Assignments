/* 
Write a function that returns if a string of paranthesis are matched. 
You are required to use the STL stack datastructure in your code for O(n) time complexity.
See 5.17 in the book for problem description and a stack based algorithm. 
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std; 
  
// function to check if paranthesis are balanced 
bool areParanthesisBalanced(string expr) { 
// Your code here

stack<char> S;

 for(int i = 0; i < expr.length() ; i++) {
     
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
        S.push(expr[i]);
        }
        
        else {
                 if(S.empty()) {
                     return false;
                 }
                 
              char H = S.top();
              
              if (expr[i] == ')' && H == '(' || expr[i] == ']' && H == '[' || expr[i] == '}' && H == '{') {
                  S.pop();
              }
 }
 }
        if (S.empty()) {
                return true;
        }
            else {
                return false;
            }
}


  
// Test - DO NOT MODIFY
int main() 
{ 
    vector<string> parans = {"{()}[]", "[[", "))", "{[()]}", "({[])}"}; 
  	
	for(auto expr : parans) {
    	if (areParanthesisBalanced(expr)) 
        	cout << "Balanced" << endl; 
    	else
        	cout << "Not Balanced" << endl;
	} 
    return 0; 
}
