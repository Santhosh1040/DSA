#include<bits/stdc++.h>
using namespace std;

//koko eating bananas

//For 1 hour how much banana Koko can eat

//piles = [3,6,7,11] h = 8
//O/P:k = 4 [if koko eats 4 bananas per hour in 8 hours koko can finish all the piles]

//finding max from the given piles

int findmax(vector<int>& v){
    int maxi = v[0];
    for(int i = 0; i < v.size(); i++){
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

// calculate total hours 
int calculatinghours(vector<int>& v, int k){
    int totalh = 0;

    for(int i = 0; i < v.size(); i++){
        totalh += ceil((double)v[i] / (double)k);
    }
    return totalh;
}

// binary search
int eatingbananas(vector<int>& piles, int h){
    int low = 1;
    int high = findmax(piles);

    int ans = high;

    while(low <= high){
        int mid = low + (high - low) / 2;

        int totalh = calculatinghours(piles, mid);

        if(totalh <= h){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}


//Ship Packages Within D Days, Find the minimum capacity (C) required to ship all packages within D days
//weights = [1,2,3,4,5] ,D = 4
//O/P: 5  With capacity = 5 , can finish in 4 days

// function to calculate how many days needed for given capacity
int calculateDays(vector<int>& weights, int capacity) {
    int days = 1;
    int current = 0;

    for(int i = 0; i < weights.size(); i++) {
        if(current + weights[i] <= capacity) {
            current += weights[i];   // add to current day
        } else {
            days++;                  // move to next day
            current = weights[i];    // start new day with this weight
        }
    }

    return days;
}
// main function
int shipWithinDays(vector<int>& weights, int D) {
    int low = *max_element(weights.begin(), weights.end());   // max number in the gievn array 
    int high = accumulate(weights.begin(), weights.end(), 0); // total sum

    int ans = high;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        int days = calculateDays(weights, mid);

        if(days <= D) {
            ans = mid;         // valid capacity
            high = mid - 1;    // try smaller
        } else {
            low = mid + 1;     // need bigger capacity
        }
    }

    return ans;
}

