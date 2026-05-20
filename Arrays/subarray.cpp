#include<bits/stdc++.h>
using namespace std;

// Longest subarray wuth given sum K

//arr = [1,2,1,1,1]
//k = 3

//O/p:3  (from subarray [1,1,1])

// 1.two pointer
//works only for positive numbers

int longestSubarrayWithSumK(vector<int>& arr, int k) {
    int n = arr.size();
    int left = 0, sum = 0, maxLen = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right];

        // shrink window if sum exceeds k
        while (sum > k && left <= right) {
            sum -= arr[left];
            left++;
        }

        // check for valid window
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
    }

    return maxLen;
}

//2.Hashing 
//works for negative and non negative numbers
int longestSubarrayWithSumK(vector<int>& arr,int k){

    unordered_map<int,int> mpp;

    int prefix=0;
    int maxLen=0;

    for(int i=0;i<arr.size();i++){

        prefix += arr[i];

        if(prefix==k)
            maxLen=i+1;

        if(mpp.find(prefix-k)!=mpp.end()){
            maxLen=max(maxLen,
                       i-mpp[prefix-k]);
        }

        if(mpp.find(prefix)==mpp.end()){
            mpp[prefix]=i;
        }
    }

    return maxLen;
}

//Smallest subarray with sum exactly K)
//I/P:[5 3 7 14 18 1], k=15
//O/p:0 2 [5+3+7 =15]

int smallestsubarrawithsumk(vector<int>&arr,int k){
    int n=arr.size();
    int left=0;
    int sum=0;

   for(int right=0; right<n; right++){

      sum+=arr[right];

      while(sum>k){
         sum-=arr[left];
         left++;
      }

      if(sum==k){
         cout<<left<<" "<<right;
         return 0;
      }
   }
   cout<<"Not Found";

   return 0;

}

//Maximum subarray sum kadane's algorithm
//prints the maxsum

int maxSubArray(vector<int>& nums) {
    int currentSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

//primts max sum and the subarray
void maxsumsubarray(vector<int>& nums){

    int currentsum=nums[0];
    int maxsum=nums[0];

    int start=0;
    int end=0;
    int temp=0;

    for(int i=1;i<nums.size();i++){

        if(nums[i] > currentsum+nums[i]){
            currentsum=nums[i];
            temp=i;
        }

        else{
            currentsum=currentsum+nums[i];
        }

        if(currentsum>maxsum){

            maxsum=currentsum;

            start=temp;
            end=i;
        }
    }

    cout<<"Maximum Sum: "<<maxsum<<endl;

    cout<<"Subarray: ";

    for(int i=start;i<=end;i++){
        cout<<nums[i]<<" ";
    }

    cout<<endl;
}
int main(){

    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    maxsumsubarray(nums);

    return 0;
}







//Maximun Product Subarray
//Input: nums = [2,3,-2,4]
//Output: 6

int maxproduct(vector<int>&nums){
    int maxi=nums[0];
    int mini=nums[0];
    int ans=nums[0];

    for(int i=1;i<nums.size();i++){
        if(nums[i]<0){
            swap(maxi,mini);
        }
        maxi=max(nums[i],maxi*nums[i]);
        mini=min(nums[i],mini*nums[i]);

        ans=max(ans,maxi);
    }
    return ans;

}

//Longest subarray with sum < K
//I/P:2 1 3 2 4   k=6
//O/p:2    (2 1 3  (sum=6 equal not allowed),2 1(3), 1 3 2  (sum=6 not allowed ) , 3 2(5)  )


int main(){
    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;


    int left=0;
    int sum=0;
    int maxlen=0;

    for(int right=0;right<n;right++){
        sum+=arr[right];

        while(sum>=k){
            sum-=arr[left];
            left++;
        }
        maxlen=max(maxlen,right-left+1);

    }
    cout<<maxlen;
    return 0;
}

