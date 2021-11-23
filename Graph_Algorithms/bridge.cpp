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

// This Program finds bridging edges in a undirected graph

vector<bool> vst;
vector<int> ids,link;
int id=0;

void dfs(vector<int> v[],int parent,int cur){
	// we initialize the currrent index of ods and link
	ids[cur]=link[cur]=id;
	id++;
	vst[cur]=true;
	for(auto it:v[cur]){
		// if the dfs tries to go back one step where it came from
		// we don't let it
		if(it==parent) continue;
		if(!vst[it]){
			dfs(v,cur,it);
			// if the cur node is unvisited we
			link[cur]=min(link[cur],link[it]);
		}
		else
			link[cur]=min(link[cur],ids[it]);
		// Outputting the bridges
		// The condition is : current id < to's  link
		if(ids[cur]<link[it]) cout<<cur+1<<"->"<<it+1<<"\n";
	}
}

void find_bridges(vector<int> v[],int n){
	cout<<"\nBridges are : \n";
	loop(i,n)
		if(!vst[i])
		// -1 is bcz the starting node we don't know its parent 
		dfs(v,-1,i);
}

main(){
	int n;
	cout<<"Enter # of nodes : ";
	cin>>n;
	vst.resize(n,false);
	link.resize(n);
	ids.resize(n);
	vector<int> adj[n];


	//Inputting the weighted graph 
	cout<<"Enter node weight pairs for each node :\n";
	loop(i,n){
		cout<<i+1<<" : ";
		int u;
		while(1){
			cin>>u;
			if(!u) break;
			if(u>n) continue;
			u--;
			adj[i].pb(u);
			adj[u].pb(i);
		}
	}
	// Displaying the graph
	cout<<"\nGRAPH\n";
	loop(i,n){
		cout<<i+1<<" : ";
		for(auto it: adj[i]){
			cout<<it+1<<" ";
		}
		cout<<"\n";
	}
	// Find bridge function 
	find_bridges(adj,n);
}
