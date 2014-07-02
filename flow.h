#include <vector>
#include <map> 

class Flow
{
	static const int INF=1<<25;
	std::vector<int> capacity,flow,start,end;
	int n,destination;
	std::vector<bool> mark;
	std::vector<std::vector<int> > next,prev;
	std::map<int,int> cap;
	std::vector <bool> Div ;  // it is false for one side of the mincut and true for the other side.
	void relax() ;
	int dfs(int s,int t) ;
public:

	void setDiv( std::vector <bool> A) ;
	std::vector <bool>  getDiv() ;
	int maxFlow(int start,int end) ;
	Flow(int n) ;
	void push_back(int left,int right,int weight) ;
};
