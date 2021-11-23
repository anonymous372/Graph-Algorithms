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

//
vector<bool> inStack;
vector<int> ids,link;
stack<int> s;
int id=0;

void dfs(vector<int> v[],int at){
	// Make the node visited in ids & inStack
	ids[at]=link[at]=id++;
	s.push(at);
	inStack[at]=true;
	for(auto it : v[at]){
		// If the node is not visted dfs on it 
		if(ids[it]==-1) dfs(v,it);
		// else if its on stack then,
		if(inStack[it]){
			link[at]=min(link[at],link[it]);
		}
	}
	// Now if we traversed the whole component and we
	// are back at the starting point of cmpnt
	if(ids[at]==link[at]){
		// Pop all the item of that very component
		while(s.top()!=at){
			inStack[s.top()]=false;
			s.pop();
		}
		s.pop();
		inStack[at]=false;
	}
}

void taarjan(vector<int> v[],int n){
	// doing DFS from all unvisited nodes
	loop(i,n)
		if(ids[i]==-1)
			dfs(v,i);

	// Displaying the components
	id=0;
	cout<<"Components are : \n";
	for(auto it:link) cout<<++id<<" : "<<it<<"\n";
}

main(){
	int n;
	cout<<"Enter # of nodes : ";
	cin>>n;
	inStack.resize(n,false);
	link.resize(n);
	ids.resize(n,-1);
	vector<int> adj[n];

	//Inputting the weighted graph 
	cout<<"Enter node connected each node:\n";
	loop(i,n){
		cout<<i+1<<" : ";
		int u;
		while(1){
			cin>>u;
			if(!u) break;
			if(u>n) continue;
			u--;
			adj[i].pb(u);
		}
	}	
	// Now we have a directed graph
	// Displaying the graph
	cout<<"\nGRAPH\n";
	loop(i,n){
		cout<<i+1<<" : ";
		for(auto it: adj[i]){
			cout<<it+1<<" ";
		}
		cout<<"\n";
	}
	// Now we gonna find SCC in the graph adj 
	taarjan(adj,n);

	// Enter # of nodes : 8
	// Enter node connected each node :
	// 2 0 
	// 3 0 
	// 1 0 
	// 5 8 0 
	// 6 0 
	// 1 7 0 
	// 3 5 1 0 
	// 6 4 0 
}