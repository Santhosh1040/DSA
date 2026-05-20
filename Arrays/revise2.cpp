#include<bits/stdc++.h>
using namespace std;

//Two sum
//1.Hashing

//Input: nums = [2,7,11,15], target = 9
//Output: [0,1]

vector<int>twosum(vector<int>&nums,int target){
    map<int,int>mpp;
    for(int i=0;i<nums.size();i++){
        int num=nums[i];
        int needed=target-num;

        if(mpp.find(needed)!=mpp.end()){
            return {mpp[needed],i};   //[index, index]
        }
        mpp[num]=i;

    }
    return{-1,-1};
}

//2.two pointer
vector<int> twoSum(vector<int>& arr,int target){

   int left=0;
   int right=arr.size()-1;

   while(left<right){

      int sum=arr[left]+arr[right];

      if(sum==target)
         return {left,right};

      else if(sum<target)
         left++;

      else
         right--;
   }

   return {-1,-1};
}

//3 sum
//Find all groups of 3 numbers such that their sum is 0
//Input: nums = [-1,0,1,2,-1,-4]
//Output: [[-1,-1,2],[-1,0,1]]

 vector<vector<int>> threeSum(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue; //ignore duplicates

        int j=i+1;
        int k=n-1;

        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];

            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                ans.push_back({nums[i],nums[j],nums[k]}); //pushes the triplets to ans that gives sum as 0 
                j++;
                k--;

                while(j<k && nums[j]==nums[j-1]) j++; //ignores dublicates
                while(j<k && nums[k]==nums[k+1]) k--; ////ignores dublicates


            }
        }
    }
    return ans;


 }

//Best time to buy and sell stock

//input: prices = [7,1,5,3,6,4]
//Output: 5
//Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

int maxprofit(vector<int>&prices){
    int mini=prices[0];
    int profit=0;

    for(int i=1;i<prices.size();i++){
        int cost=prices[i]-mini;
        profit=max(profit,cost);
        mini=min(mini,prices[i]);
    }
    return profit;
}

//Product of Array Except Self
//Input: nums = [1,2,3,4]
//Output: [24,12,8,6]

 vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> answer(n, 1); //answer array with neutral number 1 
        // prefix left side products
        for(int i=1;i<n;i++){
            answer[i]=answer[i-1]*nums[i-1];
        }
        //suffix right side 
        int right = 1;
        for(int i=n-1;i>=0;i--){
            answer[i]=answer[i]*right;
            right*=nums[i];
        }
        return answer;

        
    }


//Permutations

//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

vector<vector<int>>permutation(vector<int>nums){
    vector<vector<int>>result;
    sort(nums.begin(),nums.end());

    do{
        result.push_back(nums);
    }while(next_permutation(nums.begin(),nums.end()));

    return result;

}


//Find minimum in rotated sorted array
//Input: nums = [3,4,5,1,2]
//Output: 1
//Explanation: The original array was [1,2,3,4,5] rotated 3 times.

int findmin(vector<int>&nums){
    int left=0;
    int right=nums.size()-1;

    while(left<right){
        int mid=left+(right-left)/2;

        if(nums[mid]>right){
            left=mid+1;
        }
        else{
            right=mid;
        }
    }
    return nums[left];
}

//search in rotated array
//Input: nums = [4,5,6,7,0,1,2], target = 0
//Output: 4

int searchinroatatedarray(vector<int>&nums,int target){
    int left=0;
    int right=nums.size()-1;

    while(left<=right){
        int mid=left+(right-left)/2;

        if(nums[mid]==target) return mid;
         // Left half sorted
        if(nums[left]<=nums[mid]){
            if(nums[left]<=target && target<nums[mid]){  //Target lies inside the left sorted range
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
         // right half sorted
        else{
            if(nums[mid]<target && target<=nums[right]){ //Target lies inside the right half
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
    }
    return -1;
}



 //Rain water tapping
 //Pick 2 lines and find the maximum water that can be hold by the lines
int trap(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;

    int maxwater=0;

    while(left<right){
        int h=min(height[left],height[right]);
        int w=right-left;

        maxwater=max(maxwater,h*w);

        if(height[left]<height[right]){
            left++;
        }
        else{
            right--;
        }
    }
    return maxwater;

}

//max min
pair<int,int> findMaxMin(vector<int>& nums){

    int maxi = INT_MIN;
    int mini = INT_MAX;

    for(int i=0;i<nums.size();i++){

        if(nums[i] > maxi){
            maxi = nums[i];
        }

        if(nums[i] < mini){
            mini = nums[i];
        }
    }

    return {maxi, mini};
}


//Range Sum Query
//arr = [3,5,2,8,6]
//L = 1
//R = 3
//O/p: 15 (5 + 2 + 8 = 15)

int rangesum(vector<int>&nums,int l,int r){
    vector<int>prefix(nums.size());

    prefix[0]=nums[0];

    for(int i=1;i<nums.size();i++){
        prefix[i]=prefix[i-1]+nums[i];  //We calculate prefix for the whole array and store it in prefix array 


    }
    if(l==0){
        return prefix[r];
    }

    return prefix[r]-prefix[l-r];  //calculates the asked prefix with the given L and R
}

//Find equilibrium index

//arr = [1,3,5,2,2]
//O/P:2 [index]              explanation: 1+3 =4 , 2+2=4 so we are in 5 which is index 2 that is equilibrium index 

int findequilibriumindex(vector<int>&arr){
    int leftsum=0;
    int total=0;

    for(int num:arr){
        total+=num;

    }

    for(int i=0;i<arr.size();i++){
        total-=arr[i];

        if(total==leftsum){
            return i;
        }

        leftsum+=arr[i];
    }
    return -1;
}


//Dutch national Flag algorithm
//I/P: [2 0 2 1 1 0]
//O/P:[0 0 1 1 2 2]

int main(){
    //Input
    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //logic
    int low=0;
    int mid=0;
    int high=n-1;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(mid==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }

    }

    //Output
    for(int x:arr){
        cout<<x<<"";

    }
    return 0;
}

//Odd Occurring Element 
//Every element appears twice except one.Find single odd-occurring element.
//I/p:1 1 2 2 3 4 4
//O/P:3 

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int low=0;
    int high=n-1;

    while(low<high){
        int mid=(low+high)/2;

        if(mid%2==1){
            mid--;
        }
        else if(arr[mid]==arr[mid+1]){ //If equal pair is intact ,Single element must be on RIGHT.
            low=mid+2; //skip this pair
        }
        else{
            high=mid; //Single element is at mid or left side.
        }
    }
    cout<<arr[low];
    return 0;



}