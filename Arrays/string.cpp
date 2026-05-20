#include<bits/stdc++.h>
using namespace std;

//reverse string 
//I/p: hello
//O/p: olleh
string reversestring(string s){
        int left=0 , right=s.length()-1;
        while(left<right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return s;

}

//palindrome
bool ispalindrome(string s){
    int left=0,right=s.size()-1;

    while(left<right){
        if(s[left]!=s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}
//remove duplicates

//Input:  "programming"
//Output: "progamin"

string removeduplicates(string s){
    unordered_set<char>seen;
    string result="";

    for(char c:s){
        if(seen.find(c)==seen.end()){
           seen.insert(c);
           result+=c;
        }
    }
    return result;
}
//Character Frequency Count
unordered_map<char,int> charFrequency(string s) {
    unordered_map<char,int> freq;

    for (char c : s) {
        freq[c]++;
    }
    return freq;
}

/*
If only lowercase letters:

vector<int> freq(26, 0);
 for (char c : s) {
    freq[c - 'a']++;
}
*/

//First Non-Repeating Character

// s = "banana"
//o/p: b

char firstnonrepeatingcharacter(string s){
    vector<int>freq(256,0);
    for(char c:s){
        freq[c]++;
    }
    for(char c:s){
        if(freq[c]==1){
            return c;
        }

    }
    return '$';
}

//first non repeating character
//I/p:"zopsmart" O/p:0 (z is the first non repeating character its index is 0 so O/p is 0)

int firstNonRepeatingChar(string s){
    int n=s.length();
    unordered_map<char,int>freq;

    for(char c:s){
        freq[c]++;
    }

    for(int i=0;i<n;i++){
        if(freq[s[i]]==1){
            return i;
        }
    }
    return -1;
}

//count vowels and consoants

pair<int,int>countvowelsconosants(string s){
    int v=0,c=0;

    for(char c:s){
        //isalpha checks Is character a letter
        if(isalpha(c)){
            char ch=tolower(c); //Converts uppercase → lowercase
            if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                v++;
            }
            else{
                c++;
            }
        }
    }
    return {v,c};
}

//Reverse Words in a String
//Input:  "hello world"
//Output: "world hello"
string reverseWords(string s) {
    reverse(s.begin(), s.end());   //Reverse whole string
    int start = 0;                

    for (int i = 0; i <= s.length(); i++) {
        if (i == s.length() || s[i] == ' ') {
            reverse(s.begin() + start, s.begin() + i); //Reverse current word
            start = i + 1; //Next word begins after space.
        }
    }
    return s;
}


//input: aaa bbb ccc
//output: 3

int countWords(string s) {
    stringstream ss(s);
    string word;
    int count = 0;

    while (ss >> word)
        count++;

    return count;
}
//count number of substrings
//s="abcd" output:10

int countsubstring(string s){
    int n = s.size();
    
    return n*(n+1)/2;
}

//Longest Substring Without Repeating Characters
//s = "abcabcbb" Longest unique substring:abc
//output 3
 
int longestSubstring(string s) {

    vector<int> last(256, -1);

    int left = 0, maxLen = 0;

    for (int right = 0; right < s.size(); right++) {

        if (last[s[right]] >= left) {
            left = last[s[right]] + 1;
        }

        last[s[right]] = right;

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}


//Longest Palindromic Substring
//I/p: babad  O/p:bab

string longestSubstringpalindrome(string s){
    int start=0;
    int maxlen = 1;
    //expand is a helper function
    auto expand=[&](int l,int r){  //from a center, we expand outward: left moves left , right moves right
        while(l>=0 && r<s.size()&&s[l]==s[r]){
            if(r-l+1>maxlen){  //r-l+1 is the  length of the current substring
                start=l;
                maxlen=r-l+1;
            }
            l--;
            r++;

        }

    };
    for(int i=0;i<s.size();i++){
        expand(i,i);//Odd palindrome
        expand(i,i+1);//even palindrome
    }
    return s.substr(start,maxlen);
    

}

//Palindromic Substrings
//Input: s = "aaa"
//Output: 6   [Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa"]

int countsubstring(string s){
    int count=0;

    auto expand=[&](int l,int r){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            count++;
            l--;
            r++;
        }

    };

    for(int i=0;i<s.size();i++){
        expand(i,i);
        expand(i,i+1);
    }
    return count;
}

//Valid Anagram 
//Input: s = "anagram", t = "nagaram"
//O/P: True;

bool isanagram(string s,string t){

    if(s.length()!=t.length()) return false;

    unordered_map<char,int>freq;
    for(char c:s){
        freq[c]++;
    }
    for(char c:t){
        freq[c]--;
        if(freq[c]<0){
            return false;
        }
        return true;
    }
    
}
 
//Valid Paranthesis
//Input: s = "()[]{}"
//O/P: True;

 bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> bracketPairs = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for(char ch:s){
            if(bracketPairs.count(ch)){
                if(st.empty() || st.top()!=bracketPairs[ch]){
                    return false;
                }
                st.pop();
            }
                else{
                    st.push(ch);
                }

            }
            return st.empty();
        }

    

// Binary String to Integer
//Input: 1011,  Output:11

int binaryToDecimal(string s) {
    int num = 0;
    for (char c : s) {
        num = num * 2 + (c - '0');
    }
    return num;
}

//Decimal to Roman
//I/p: 58 O/p:LVIII

string intToRoman(int num) {
    vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    string result = "";
    for (int i = 0; i < values.size(); i++) {
        while (num >= values[i]) {
            num -= values[i];
            result += symbols[i];
        }
    }
    return result;
}

//Generate Valid IP Addresses
//I/p:25525511135
//O/p:255.255.11.135
//    255.255.111.35

bool valid(string s){
    //If number has multiple digits AND starts with 0 → invalid
    if(s.size()>1 && s[0]=='0') return false;
    int num=stoi(s);  //stoi converts a numeric string into an int.
    return num>=0 && num<=255;
}

vector<string> restoreip(string s){
    vector<string> res;
    int n = s.size();

    for(int i=1;i<n-2;i++)
    for(int j=i+1;j<n-1;j++)
    for(int k=j+1;k<n;k++){
        string a=s.substr(0,i);
        string b=s.substr(i,j-i);
        string c=s.substr(j,k-j);
        string d=s.substr(k);

        if (valid(a) && valid(b) && valid(c) && valid(d))
            res.push_back(a+"."+b+"."+c+"."+d);
    }

    return res;
}


//String Matching (Substring)
//text = "hello world" pattern = "world"
//O/p:true

bool containsSubstring(string text, string pattern) {
    return text.find(pattern) != string::npos;
}

//String Compression
//I/p:aaabbCCC
//O/P:a3b2C3

int countstring(string s){
    string ans="";

   int count=1;

   for(int i=1;i<=s.size();i++){

      if(i<s.size() && s[i]==s[i-1]){
         count++;
      }

      else{
         ans+=s[i-1];
         ans+=to_string(count);
         count=1;
      }
   }

   cout<<ans;
}