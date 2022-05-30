#include<iostream>
#include <algorithm>
using namespace std;
class edge{
	public:
		int source;
		int dest;
		int weight;
};
bool compare(edge e1,edge e2)
{
	return e1.weight < e2.weight;
}
int findparent(int v,int *parent)
{
	if(parent[v]==v)
{
		return v;
}
return findparent(parent[v],parent);
}
void kruskal(edge *input,int n,int e)
{
	sort(input,input+e,compare);
	
	edge *output=new edge[n-1];
	int *parent=new int[n];
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
	}
	int count=0;
	int i=0;
	while(count!=n-1)
	{ edge currentedge=input[i];
	 int source=findparent(currentedge.source,parent);
	 int dest=findparent(currentedge.dest,parent);
	 if(source!=dest)
	 {
	  	output[count]=input[i];
	 	count++;
	 	parent[source]=dest;
	 	
	 }
	 i++;
	}
	for(int i=0;i<n-1;i++)
	{
		cout<<output[i].source<<""<<output[i].dest<<""<<output[i].weight;
	}
}
int main()
{
	int n,e;
	cin>>n>>e;
	edge *input=new edge[e];
	for(int i=0;i<e;i++)
	{
	    int s,d,w;
		cin>>s>>d>>w;
		input[i].source=s;
		input[i].dest=d;
		input[i].weight=w;	
	}
	kruskal(input,n,e);
	
	
}
