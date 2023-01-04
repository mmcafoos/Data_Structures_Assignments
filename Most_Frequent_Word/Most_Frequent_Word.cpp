// For an input string of words, find the most frequently occuring word. In case of ties, report any one of them. 
// Your algorithm should be O(n) time where n is the number of words in the string
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;


string findWord(vector<string>& tokens);
 
int main() {
	string line = "I felt happy because I saw the others were happy and because I knew I should feel happy but I wasn’t really happy";
	
	// Convert string to a vector of words
	char delimiter = ' ';
    string token;
    istringstream tokenStream(line);
	vector<string> tokens;
	while (getline(tokenStream, token, delimiter)) {
	tokens.push_back(token);
	}	
    cout << "The most frequently occuring word is: " << findWord(tokens) << endl;
	
}

string findWord(vector<string>& tokens) {
// Your code here

//hash table seemed to be the best way to solve this, plus with #include <unordered_map>
//I wasn't sure if it was required or not

unordered_map <string, int> m; 
//Creates map of words
for(int i = 0 ; i < tokens.size() ; i++){
  if(m.count(tokens[i]) == 0){
    m[tokens[i]] = 1;
  }
  else{
    m[tokens[i]] ++;
  }
}
//Finds word with maximum frequency 
string frequency = "";
int MAXIMUM_POWER = INT8_MIN;
for(auto x : m){
  if(x.second > MAXIMUM_POWER){
    frequency = x.first;
    MAXIMUM_POWER = x.second;
  }
  
}
//Since there are no ties in the string, I didn't implement something for that

return frequency;


}


