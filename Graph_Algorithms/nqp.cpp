#include<bits/stdc++.h>
using namespace std;
#define bug cout<<" *H* ";
#define nxtl cout<<"\n";
//fors
#define loop(i,b) for(int i=0;i<b;i++)
#define rloop(i,b) for(int i=b;i>=0;i--) //from [b to 0]  	
#define arin(ar)  loop(i,sizeof(ar)/sizeof(ar[0])) cin>>ar[i];
#define show(ar)  loop(i,sizeof(ar)/sizeof(ar[0])) cout<<ar[i]<<" ";
#define For(i,a,b) for (int i = a;(a<b)?i<b:i>=b;(a<b)?i++:i--)//from [a to b)or[b to a]

//Vector
#define vec(v) vector<int> v
#define pb(a) push_back(a)
#define pii pair<int,int>
#define pbp(a,b) push_back({a,b})
#define all(a) (a.begin(),a.end()) 
#define fs first
#define sc second


vector<vector<int>> grid; 
vector<int> row,col,diag1,diag2;

int cnt=0;

void solve(int r,int c,int n){
	cout<<"("<<r<<", "<<c<<"),";
	if(!row[r] and !col[c] and !diag1[r+c] and !diag2[n-1-r+c]){
		grid[r][c] = row[r] = col[c] = diag1[r+c] = diag2[n-1-r+c] = 1;
		cnt++;
	}
	loop(i,n-1){
		solve(r,i+1,n);
	}
}	

main()
{
	int n;
	cout<<"Enter size of grid : ";
	cin>>n;
	grid.resize(n,vector<int>(n,0));
	row.resize(n,0);
	col.resize(n,0);
	diag1.resize(2*n-1,0);
	diag2.resize(2*n-1,0);

	solve(0,0,n);
	
	nxtl;
	nxtl;
	
	loop(i,n){
		for(auto it : grid[i]) if(it) cout<<"Q "; else cout<<". "; nxtl;
	}

	//    0 1 2 3 4  
	//  0 . . . . . 4
	//  1 . . . . . 5
	//  2 . . . . . 6
	//  3 . . . . . 7
	//  4 . . . . . 8
	//    4 5 6 7 8 

	//    4 5 6 7 8
	//  4 . . . . . 8
	//  3 . . . . . 7
	//  2 . . . . . 6
	//  1 . . . . . 5 
	//  0 . . . . . 4
	//    0 1 2 3 4
	cerr<<"\nTime : "<<(float)clock()/CLOCKS_PER_SEC<<endl;
}
