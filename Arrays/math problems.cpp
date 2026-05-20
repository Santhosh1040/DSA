#include <bits/stdc++.h>
using namespace std;
//Toggle Bits of Decimal Number
//I/P:10
//O/p:5

//conver given input to binary and toggle the bits and again convert the binary to decimal
int main(){
    int n;
    cin>>n;

    int bits=0;
    int temp=0;

    while(temp>0){
        bits++;
        temp=temp/2;
    }
    int allones=(1<<bits)-1;  //convert the binary to all ones
    int ans=allones^n;//doing xor will give the output

    cout<<ans;
    return 0;
}

//House Robber
//Houses in line Each has money Cannot rob adjacent houses Find maximum money possible.
//I/P:2 7 9 3 1
//O/P:12  [2 +9 +1 =12]

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if(n==1){
        cout<<arr[0];
        return 0;
    }
    vector<int>dp(n);

    dp[0]=arr[0];     //If only one house exists:
    dp[1]=max(arr[0],arr[1]); //First two houses cant rob both so max of 2 house 

    for(int i=2;i<n;i++){ //Start from third house.
        dp[i]=max(dp[i-1],arr[i]+dp[i-2]);

    }
    cout<<dp[n-1];
    return 0;

}

/*
Prime and Digit sum multiplication 
IP: 
6 8

O/P:
52

Explanation:
6th prime = 13
digit sum = 1+3 = 4
result = 13 X 4 = 52

second input number 8 is used nowhere

*/

bool isprime(int num){
    if(num<2){
        return false;
    }

    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int digitsum(int x){
    while(x>=10){
        int sum=0;

        while(x>0){
            sum+=x%10;
            x/=10;
        }
        x=sum;
    }
    return x;

}

int main(){
    int m,n;
    cin>>m>>n;

    int cnt=0;
    int num=2;
    int prime;

    while(cnt<m){
        if(isprime(num)){
            cnt++;

            if(cnt==m){
                prime=num;
                break;

            }

        }
        num++;
    }
    int digit=digitsum(prime);
    cout<<prime*digit;
    return 0;
}
//Calculate speed in km/h

//I/P: Distance = 30KM , Time = 30 min
//O/P: 60
int main(){
    int dist;
    int time;
    cin>>dist>>time;

    if(time==0 || time>60){
        cout<<"Error";
        return 0;
    }
    double timeinhrs = time/60.0;
    int speed = dist/timeinhrs;

    cout<<speed;
    return 0;
}


int main(){
    int m;
    cin>>m;

    vector<vector<int>> a(m,vector<int>(2)); //m rows with 2 columns
    
    for(int i=0;i<m;i++){
        cin>>a[i][0]>>a[i][1];
    }
    int sx,sy;
    cin>>sx>>sy;

    for(int i=0;i<m;i++){
        int newx=a[i][0]*sx;
        int newy=a[i][1]*sx;

        cout<<newx<<""<<newy<<endl;
        
    }
    return 0;
}

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    double  sum=0;
    double  avg=0;
    int cnt=0;
    for(int i=0;i<arr.size();i++){
         sum=sum+arr[i];
         avg=sum/(i+1);

         if(arr[i]>=avg){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<int>> a(m,vector<int>(n));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

        }
    }
}


int main(){
    int medid;
    int stocklevel;
    cin>>medid>>stocklevel;

    if(stocklevel==2){
        cout<<"Full Stock";
    }
    else if(stocklevel==1){
        cout<<"Half Stock";
    }
    else if(stocklevel==0){
        cout<<"Out of stock and Reorder required";
    }
    else{
        cout<<"Stock is sufficient";
    }
    return 0;


}


int minboats(vector<int>&arr,int limits){
    int boats=0;
    sort(arr.begin(),arr.end());
    int left=0;
    int right=arr.size()-1;

   while(left<=right){
    if(arr[left]<=arr[right]){
        left++;
        right--;
    }
    else{
        right--;
    }
    boats++;
   }
   return boats;


    
}