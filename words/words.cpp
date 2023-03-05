#include <iostream> // figure out a way to use cstdio? scanf can't process strings as easily
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> splitByDelim(string originalStr, string delimiter) {
	vector<string> newVector = {};
	size_t pos = 0;
    string token;
    while ((pos = originalStr.find(delimiter)) != string::npos) {
        token = originalStr.substr(0, pos);
        newVector.push_back(token);
        originalStr.erase(0, pos + delimiter.length());
    }
    newVector.push_back(originalStr);

	return newVector;
}

void helper_printVectorContents(vector<string> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i) << '\n';
	}
}

void helper_reverseStr(string& str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

vector<string> processInput() {
	// remove square brackets and turns string into a vector
    string userInput, newInput;
    getline(cin, userInput); // accepts user input
    
    int numChars = userInput.size();
    newInput = userInput.substr(1, numChars - 2); // removes square brackets
   
    // splits newInput by delimiter <<', >>
	vector<string> stringArray = splitByDelim(newInput, "', ");

	vector<string> returnArray = {}; // creates new return vetor
	for (int i = 0; i < stringArray.size(); i++) {
		if (i == stringArray.size() - 1) { // removes extra quotes
			string lastStr = (stringArray[i]).substr(1, stringArray[i].size() - 2);
			returnArray.push_back(lastStr);
			break;
		}
		string newStr = (stringArray[i]).substr(1, stringArray[i].size());
		returnArray.push_back(newStr); // pushes back onto a return vector
	}

	return returnArray;
}

void longest(vector<string> array) {
	vector<string> newArray; // creates a new array of strings w/o punctuation
	for (int i = 0; i < array.size(); i++) {
		string currentStr = array[i];
		auto it = remove_if(currentStr.begin(), currentStr.end(), [](char const &c) {
        	return ispunct(c); // removes punctuation in place
    	});
 
    	currentStr.erase(it, currentStr.end());  // deletes part of the string to move onto next part
		newArray.push_back(currentStr);
	}

	auto longestStr = max_element(newArray.begin(), newArray.end(), [](const auto& a, const auto& b) { return a.size() < b.size();});

	// reference longestStr by *longestStr
	int longestStrIndex = distance(newArray.begin(), longestStr); // zero based pos of longestStrIndex

	string ls = array[longestStrIndex];
	cout << ls << "\n"; // output line 1

	// 1. split *longestStr by space - remember we need to get rid of punctuation. (done)
	// 2. find lw = longest word in this split list. (done) 
	// 3. if count of lw = 1, print as normal (done)
	// 4. else if count of lw > 1, print lw reversed. (done)

	vector<string> longestStrSplit = splitByDelim(*longestStr, " ");
	auto lw = max_element(longestStrSplit.begin(), longestStrSplit.end(),
                               [](const auto& a, const auto& b) {
                                   return a.size() < b.size();
                               });

	int occurencesCounter = count(longestStrSplit.begin(), longestStrSplit.end(), *lw); // step 2
	if (occurencesCounter > 1) {
		helper_reverseStr(*lw); // step 4
	}
	cout << *lw; // step 3 and 4 combined
}

int main() {
	vector<string> wordsArray = processInput();
	longest(wordsArray);
}
