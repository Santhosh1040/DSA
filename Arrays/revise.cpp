#include<bits/stdc++.h>
using namespace std;

//Use a hashmap when counting / frequency is involved

/*

if array is sorted - Two pointer
unsorted array - hashing

“first unique / non-repeating” - Hashing / Frequency

“longest / smallest window”	- Sliding Window

“continuous subarray / substring”	- Two pointers

“move zeros / rearrange” - Two pointers

“closest / max sum pair” - Two pointers / Greedy

“missing / repeating” - Math / XOR / Hashing

“session monitoring / logs” - Sliding window + hashmap

*/

//maximum count of a number in an array 
int freqcount(vector<int>& arr){
    unordered_map<int,int>freq;
    int maxfreq=0;

    for(int x:arr){
        freq[x]++;
        maxfreq=max(maxfreq,freq[x]);
    }

    return maxfreq;
    

}

//largest element in an array
int largest (vector<int>& arr,int n){
    int largest = arr[0];

    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    return largest;
}

//smallest element in an array

int smallest (vector<int>&arr,int n){
    int smallest=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<smallest){
            smallest=arr[i];
        }

    }
    return smallest;
}

//second largest

int secondlargest(vector<int>&arr,int n){
    int largest=arr[0];
    int slargest=-1;

    for(int i=1;i<n;i++){
        if(arr[i]>largest){
        slargest=largest;
        largest=arr[i];
        }
    else if(arr[i]<largest && arr[i]>slargest){
        slargest=arr[i];
    }

  }
  return slargest;
}

//second smallest 

int secondsmallest(vector<int>&arr,int n){
    int smallest=arr[0];
    int ssmallest=-1;

    for(int i=1;i<n;i++){
        if(arr[i]<smallest){
            ssmallest=smallest;
            smallest=arr[i];
        }
        else if(arr[i]>smallest && arr[i]<ssmallest){
            ssmallest=arr[i];
        }
    }
    return ssmallest;
}



//Majority element n/2

//eg: arr[]=[2,2,3,3,1,2,2] n=7 

//n/2=7/2 , n=3 2 appears 4 times so o/p is 4 

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> freq;
    int n = nums.size();

    for (int x : nums) {
        freq[x]++;
    }

    for (auto &it : freq) {
        if (it.second > n / 2) {
            return it.first;
        }
    }

    return -1;
}

//optimal moore's voting algorithm for majority element n/2

int majoritymoore(vector<int>&arr,int n){
    int el;
    int cnt=0;

    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt++;
            el=arr[i];
        }
        else if(el==arr[i]){
            cnt++;
        }
        else{
            cnt--;
        }
    }
}

//reverse array
void reversearray(vector<int>&arr,int left,int right){
    while(left<right){
        swap(arr[left],arr[right]);
        left++;
        right--;
    }
}

//Left rotate 

void leftrotate(vector<int>&arr,int n,int d){
    d=d%n;
    if(d==0) return;
    //reverse d elements
    reversearray(arr,0,d-1);
    // reverse remaining element
    reversearray(arr,d,n-1);
    //reverse entire array
    reversearray(arr,0,n-1);

    
}

//right rotate

void rightrotate(vector<int>&arr,int n,int d){
    d=d%n;

    if(d==0) return;
    //reverse entire array
    reversearray(arr,0,n-1);
    //reverse d elements
    reversearray(arr,0,d-1);
    //reverse remaining element
    reversearray(arr,d,n-1);
}
//remove duplicates
vector<int> removeDuplicates(vector<int> arr) {
    unordered_set<int> seen;
    vector<int> result;

    for (int x : arr) {
        if (seen.find(x) == seen.end()) { //if number is not seen then store it 
            seen.insert(x);
            result.push_back(x);
        }
    }
    return result;
}

//missing repeating
vector<int> missingrepeating(vector<int>& nums) {
    int n = nums.size();

    vector<int> hash(n + 1, 0);

    // Count frequency
    for (int i = 0; i < n; i++) {
        hash[nums[i]]++;
    }

    int repeating = -1;
    int missing = -1;

    // Check from 1 to n
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 2) {
            repeating = i;
        }
        else if (hash[i] == 0) {
            missing = i;
        }

        if (repeating != -1 && missing != -1) {
            break;
        }
    }

    return {repeating, missing};
}
//Move All Zeros to End
void moveZeros(vector<int>& arr) {
    int j = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

//river run 
// Left to right: fill zeros using nearest left non-zero
//input: [2, 0, 3, 0, 3] , Output: arr = [2, 2, 3, 3, 3]

vector<int> replacezero(vector<int>&arr,int n){
    for(int i=1;i<n;i++){
        if(arr[i]==0){
            arr[i]=arr[i-1];
        }
         // Right to left: handle leading zeros (if any)
        //input: [0, 0, 5] , output:[5, 5, 5]
        for(int i=n-2;i>=0;i--){
            if(arr[i]==0){
                arr[i]=arr[i+1];
            }
        }

    }
    return arr;
}



//check palindrom of number
// I/p: 101 O/p: Palindrome
void reverseNum(int n) {
    int original = n;
    int reversed = 0;

    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n = n / 10;
    }

    if (reversed == original) {
        cout << "Palindrome";
    } else {
        cout << "Not palindrome";
    }
}

//Count frequency

//Input: [1,1,2,3,3,3]
//Output: 1→2, 2→1, 3→3
int countfrequency(vector<int>&arr,int n){
    map<int, int> freq;

    // Count frequency
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Print result
    for (auto it : freq) {
        cout << it.first << " -> " << it.second << endl;
    }

    return 0;

}


