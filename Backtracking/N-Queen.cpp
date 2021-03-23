/*
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. 
A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format :

Line 1 : Integer N

Output Format :

One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space

Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10
Sample Input 1:

4

Sample Output 1 :

0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 

*/
#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
int n;
bool grid[10][10]={0};
void print(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<grid[i][j]<<" ";
		}
	}
	cout<<'\n';
}
bool good(int r,int c){
	for(int i=r-1;i>=0;i--) if(grid[i][c]) return false; //check upper rows
	for(int i=r-1,j=c-1;i>=0 && j<n;i--,j--) if(grid[i][j]) return false;
	for(int i=r-1,j=c+1;i>=0 && j<n;i--,j++) if(grid[i][j]) return false;
	return true;
}
void placeQueens(int r){
	if(r==n){
		print();
		return;
	}
	for(int i=0;i<n;i++){
		if(good(r,i)){
			grid[r][i]=1;
			placeQueens(r+1);
			grid[r][i]=0;
		}
	}
	return;
}
int main(){
	IOS;
	cin>>n;
	placeQueens(0);
	return 0;
}
