#include <bits/stdc++.h>
using namespace std;

void printVectorContents(vector<string> vec) {
	for (int i = 0; i < vec.size() - 1; i++) {
		cout << vec.at(i) << "\n";
	}
    cout << vec.at(0);
}

void reverseStr(string& str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

string isPalindrome(string s) {
    // copies string
    string rev = s;
    reverseStr(rev);
    if (rev == s) {
        return rev;
    } else {
        return "not a regular";
    }
}

string replaceChars(string s) {
    // p = q test
    if (s.find('q') != string::npos) {
        replace(s.begin(), s.end(), 'q', 'p');
    }
    // b = d test
    if (s.find('d') != string::npos) {
        replace(s.begin(), s.end(), 'd', 'b');
    }
    // a = e test
    if (s.find('e') != string::npos) {
        replace(s.begin(), s.end(), 'e', 'a');
    }
    return s;
}

string isSimilarPalindrome(string s) {
    string rev = s;
    rev = replaceChars(rev);
    s = replaceChars(s);
    reverseStr(rev);
    if (s == rev) {
        return rev;
    } else {
        return "not a similar";
    }

}

bool areAnagram(string str1, string str2)
{
    // find lengths of both strings
    int n1 = str1.length();
    int n2 = str2.length();
 
    // lengths not same = surely not anagram
    if (n1 != n2) {
        return false;
    }
 
    // sort both strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
 
    // Compare sorted strings
    for (int i = 0; i < n1; i++)
        if (str1[i] != str2[i]) {
            return false;
        }
 
    return true;
}
  

int main() {
    int numStrings;
    scanf("%d", &numStrings);
    vector<string> strings;
    vector<string> results;

    for (int i = 0; i < numStrings; i++) {
        string currentInput;
        cin >> currentInput;
        strings.push_back(currentInput);
    }
    //printVectorContents(strings);

    while (strings.size() > 0) {
        string currentStr = strings.back();
        strings.pop_back();
        string currentResult;

        if (isPalindrome(currentStr) != "not a regular" && areAnagram(currentStr, isPalindrome(currentStr))) {
                currentResult = "Regular";
                results.push_back(currentResult);
        } else if (isSimilarPalindrome(currentStr) != "not a similar" && areAnagram(replaceChars(currentStr), isSimilarPalindrome(currentStr))) {
                currentResult = "Similar";
                results.push_back(currentResult);
        } else {
            currentResult = "Neither";
            results.push_back(currentResult);
        }
    }

    //printVectorContents(results);
    reverse(results.begin(), results.end());
    printVectorContents(results);

}