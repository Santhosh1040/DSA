#include<bits/stdc++.h>
using namespace std;

//longest subarray
//nums = {1, 2, 2, 3, 1}
//output=[2, 4]  , 2 3 1 from index 2 to 4 are unique 

pair<int,int>longestuniquesubarray(vector<int>&nums){
    unordered_set<int>st;

    int left=0;
    int maxlen=0;
    int start=0;
    int end=0;

    for(int right=0;right<nums.size();right++){
        while(st.count(nums[right])){
            st.erase(nums[left]);
            left++;
        }
        st.insert(nums[right]);

        if(right-left+1>maxlen){
            maxlen=right-left+1;
            start=left;
            end=right;
 
        }
    }
    return{start,end};
}

//smallest contiguous substring 
string smallestUniqueSubstring(string s) {
    unordered_set<char> st;
    int left = 0;

    int minLen = INT_MAX;
    int start = 0;

    for (int right = 0; right < s.size(); right++) {

        while (st.count(s[right])) {
            st.erase(s[left]);
            left++;
        }

        st.insert(s[right]);

        // window has all unique characters
        if (right - left + 1 < minLen) {
            minLen = right - left + 1;
            start = left;
        }
    }

    return s.substr(start, minLen);
}
