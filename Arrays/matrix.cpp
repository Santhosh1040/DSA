#include<bits/stdc++.h>
using namespace std;


//Scalar Multiplication of Matrix
//A number will be given multiply that number with the given matrix

/*
I/P:
3 3 (3x3 matrix)

1 2 3
4 5 6
7 8 9

scalar=2

O/P:
2 4 6
8 10 12
14 16 18

*/
int main(){
    int m,n,k;
    cin>>m>>n;

    int a[m][n];
    //input matrix
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cin>>k;
    

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]*k<<" ";
        }
        cout<<endl;
    }
    return 0;
}





//sum of each row

void sumofeachrow(vector<vector<int>>matrix){
    int m=matrix.size();
    int n=matrix[0].size();

    
    for(int i=0;i<m;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=matrix[i][j];

        }
        cout<<sum;
    }
    
}




//sum of col
/*
I/P:
1 2 3
4 5 6
7 8 9

O/P:
12            [1+4+7]
15            [2+5+8]
18            [3+6+9] 
*/
void sumofeachcol(vector<vector<int>>matrix){
    int m=matrix.size();
    int n=matrix[0].size();

    
    for(int j=0;j<n;j++){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=matrix[i][j];

        }
        cout<<sum;
    }
    
}



//sum of entire matrix
/*
I/P:
1 2 3
4 5 6
7 8 9

O/P:45

*/
void sumofentireamtrix(vector<vector<int>>matrix){
    int m=matrix.size();
    int n=matrix[0].size();
    int sum=0;
    
    for(int i=0;i<m;i++){
        
        for(int j=0;j<n;j++){
            sum+=matrix[i][j];

        }
        
    }
    cout<<sum;
    
}





//sum of diagonal matrix

/*
I/P:
1 2 3
4 5 6
7 8 9

O/P: 15    [1+5+9=15]
*/
void diagonalsum(vector<vector<int>>matrix){
    int m=matrix.size();
    int n=matrix[0].size();
    int sum=0;
    
    for(int i=0;i<m;i++){
      sum+=matrix[i][i];
        
    }
    cout<<sum;
    
}


//Matrix Transpose

/*
I/P: 
1 2 3
4 5 6

O/P:
1 4
2 5
3 6

*/
int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<int>> a(m,vector<int>(n));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;


}

//Rotate matrix by 90°
/*
I/P:
1 2 3
4 5 6
7 8 9

O/p:
7 4 1
8 5 2
9 6 3

*/

int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<int>> a(m,vector<int>(n));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
      // transpose
    for(int i=0;i<m;i++){
        for(int j=i+1;j<n;j++){
            swap(a[i][j],a[j][i]);
        }
    }
    // reverse rows
    for(int i=0;i<m;i++){
        reverse(a[i].begin(),a[i].end());
    }

    // print rotated matrix
for(int i=0;i<n;i++){
   for(int j=0;j<n;j++)
      cout<<a[i][j]<<" ";
   cout<<endl;
 }

    
}

//matrix Addition
/*
I/P:
1 2
3 4

5 6
7 8


O/P:
6 8
10 12
*/

int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<int>> a(m,vector<int>(n));
    
    vector<vector<int>> b(m,vector<int>(n));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]+b[i][j];
        }
        cout<<endl;
    }
    return 0;
}

//Matrix Multiplication
/*
I/P:
2 2
1 2     m x n
3 4

2 2   
5 6    n x p
7 8

O/P:
19 22
43 50

*/

int main(){

 int m,n,p;

 cin>>m>>n;
//input
 vector<vector<int>> a(m,vector<int>(n));

 for(int i=0;i<m;i++){
   for(int j=0;j<n;j++){
      cin>>a[i][j];
   }
 }

 cin>>n>>p;

 vector<vector<int>> b(n,vector<int>(p));

 for(int i=0;i<n;i++){
   for(int j=0;j<p;j++){
      cin>>b[i][j];
   }
 }

 //logic

 for(int i=0;i<m;i++){

   for(int j=0;j<p;j++){

      int prod=0;

      for(int k=0;k<n;k++){

         prod+=a[i][k]*b[k][j];
      }

      cout<<prod<<" ";
   }

   cout<<endl;
 }

}

/*
Does every row contain at least one prime number

If YES:Valid

If even one row has no prime:Not Valid

I/P:
4 6 5
7 8 10

O/P:

Valid [5 and 7 are prime]


*/

bool isPrime(int x){

   if(x<2)
      return false;

   for(int i=2;i*i<=x;i++){

      if(x%i==0)
         return false;
   }

   return true;
}

int main(){
    int m,n;
    cin>>m>>n;

    if(m<=0 || n<=0){
        cout<<"Wrong Input";
        return 0;
    }

    vector<vector<int>> a(m,vector<int>(n));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];

            if(a[i][j]<0){
                cout<<"wrong Input";
                return 0;
            }
        }
    }

    //logic

    for(int i=0;i<m;i++){
        bool hasprime=false;
        for(int j=0;j<n;j++){
            if(isPrime(a[i][j])){
                hasprime=true;
                break;
            }
        }
        if(!hasprime){
            cout<<"Not valid";
            return 0;
        }
    }
    cout<<"valid";
    return 0;




}
#include<iostream>
#include<array>
#include<string>
#include<vector>
#include<cmath>
#include<climits>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>

