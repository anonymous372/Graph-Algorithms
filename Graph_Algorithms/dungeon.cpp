#include<bits/stdc++.h>
using namespace std;

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
#define pp(a,b) push({a,b})
#define all(a) (a.begin(),a.end()) 
#define fs first
#define sc second

main()
{
	//Creating the grid
	int m,n;

	cout<<"Enter dimensions :\n";
	cout<<"N : "; cin>>n;
	cout<<"M : "; cin>>m;

	vector<int> adj[n];
	
	loop(i,n){
		adj[i].resize(m,1);
	}

	cout<<"Enter coords of obstacles :\n";

	while(1){
		int u,v;
		cout<<"(u,v) : ";
		cin>>u>>v;
		if(u==0||v==0) break;
		if(u>n||v>m) continue;
		u--; v--;
		adj[u][v]=0;
	}
	
	int start_x,start_y,end_x,end_y;

	cout<<"Enter starting point : ";
	cin>>start_x>>start_y;
	
	cout<<"Enter ending point : ";
	cin>>end_x>>end_y;
	
	start_x--; start_y--;
	end_x--; end_y--;
	cout<<start_x<<" "<<start_y;
	// Display of grid
	cout<<"\nGRID\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==start_x&&j==start_y) cout<<"S ";
			else if(i==end_x&&j==end_y) cout<<"E ";
			else if(adj[i][j]) cout<<". ";
			else cout<<"0 ";
		}
		cout<<"\n";
	}

	// Our grid is craeated now we find path
	bool vst[n][m]={0};
	vst[start_x][start_y]=true;
	
	queue<pii> q;
	q.pp(start_x,start_y);

	int next,cur,step;

	next=cur=step=0;

	//Running bfs from starting node
	while(!q.empty()){
		pii s = q.front();
		q.pop();

		int x=s.fs,y=s.sc;
		//if this satisfy this mean we completed a full layer
		//so increase the step
		if(cur==0){
			cur=next;
			next=0;

			if(cur) step++;
		}
		if(cur) cur--;
		
		if(x==end_x and y==end_y) break;

		//Looking at the adjacent squares if any sqr 
		//is not visited and is not an obstacle
		//then do the following

		int dx[]={1,-1,0,0},
			dy[]={0,0,1,-1}; 
		
		for(int i=0;i<4;i++){	
			int mx=dx[i]+x,
				my=dy[i]+y;

			if(mx<0 or my<0) continue;
			if(mx>=n or my>=m) continue;
			
			if(!vst[mx][my] && adj[mx][my]){ 
				q.pp(mx,my);
				vst[mx][my]=true;
				next++;
			}
		}
	}
	cout<<"\nStep : "<<step;
}