
/* this code is correct logic wise and complexity wise*/
#include<algorithm>
bool comp(vector<int> a, vector<int> b);
void initParent(vector<int> &parent);
int find(int u,vector<int> &parent);
void Union(int x, int y ,vector<int> &parent ,vector<int> &rank );

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
// write code
  // edges input format u v w
  sort(edges.begin(),edges.end(),comp);

  vector<int> parent(n);
  vector<int> rank(n,0);
  initParent(parent);
  int ans=0;

  // procssing all nodes in sorted order
  for(int i=0;i<edges.size();i++){
    int u = edges[i][0];
    int v = edges[i][1];
    int w= edges[i][2];
    
    // cycle detection using disjoint set data structure
    int parent_u =find(u,parent); //
    int parent_v = find(v,parent);

    // if same parent then ignore as will form cycle in tree
    // if different then union of parents
    if(parent_u != parent_v){
        Union(parent_u,parent_v,parent,rank);
        ans+=w; // as this edges is included in mst
    }

  }
  return ans;
}

bool comp(vector<int> &a, vector<int> &b){
  return a[2]<b[2] ;
}

void initParent(vector<int> &parent){
  for(int i=0;i<parent.size();i++){
    parent[i]=i; // everyone parent of itself at first
  }
}

// done path compression
int find(int u,vector<int> &parent){
  if(parent[u]== u){
    return u;
  }
  return parent[u]=find(parent[u],parent);
}

// union by rank
void Union(int x, int y ,vector<int> &parent ,vector<int> &rank ){
  /* x and y will always be the root node of tree as we have already 
  checked that in main program*/

  if(rank[x]==rank[y]){
    parent[x]=y;
    rank[y]++;
  }
  else if(rank[x]>rank[y]){
    parent[y]=x;
  }
  else{
    parent[x]=y;
  }
}
