/*
You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach its destination i.e. maze[N-1][N-1]. 
Rat can move in any direc­tion ( left, right, up and down).
Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat cannot enter into those cells and those with value 1 are open.
Input Format

The first line of input contains an integer 'N' representing 
the dimension of the maze.
The next N lines of input contain N space-separated 
integers representing the type of the cell.

Output Format :

For each test case, print the path from start position to destination position and only cells that are part of the solution path should be 1,
rest all cells should be 0.

Output for every test case will be printed in a separate line.

Note:

You do not need to print anything, it has already been taken care of. Just implement the given function.

Constraints:

0 < N < 11 0 <= Maze[i][j] <=1

Time Limit: 1sec

Sample Input 1 :

3
1 0 1
1 0 1
1 1 1

Sample Output 1 :

1 0 0 1 0 0 1 1 1 

Sample Output 1 Explanation :

Only 1 path is possible

1 0 0
1 0 0
1 1 1

Which is printed from left to right and then top to bottom in one line.
Sample Input 2 :

3
1 0 1
1 1 1
1 1 1

Sample Output 2 :

1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 

Sample Output 2 Explanation :
4 paths are possible which are printed in the required format.
*/
#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
int n;
bool grid[11][11],box[11][11]={0};
void print(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<box[i][j]<<" ";
		}
	}
	cout<<'\n';
}
void ratInMaze(int r,int c){
	if(r==n-1 && c==n-1){
		box[r][c]=1;
		print();
		return;
	}
	if(r>=n || c<0 || r<0 || c>=n) return;
	if(!grid[r][c]) return;
	if(box[r][c]) return;
	box[r][c]=1;
	ratInMaze(r+1,c);
	ratInMaze(r-1,c);
	ratInMaze(r,c+1);
	ratInMaze(r,c-1);
	box[r][c]=0;
	return;
}
int main(){
	IOS;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>grid[i][j];
		}
	}
	ratInMaze(0,0);
	return 0;
}
