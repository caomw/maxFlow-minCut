#include "flow.h"
#include <algorithm>

void Flow::relax()
{
	int count=n+1;
	n+=cap.size();

	next.resize(n+1);
	prev.resize(n+1);
	mark.resize(n+1);

	std::map<int,int> New;

	int number=start.size();

	for (std::map<int,int> :: iterator i=cap.begin();i!=cap.end();i++,count++)
	{
		New[i->first]=count;
		push_back(i->first,count,i->second);
	}
	for (int i=0;i<number;i++) 
		if (New.find(start[i]) != New.end())
			start[i]=New[start[i]];
	for (int i=0;i<start.size();i++)
	{
		next[start[i]].push_back(i);
		prev[end[i]]  .push_back(i);
	}
}



int Flow::dfs(int s,int t)
{
	if (s == destination) return(t);
	if (mark[s]) return(0);
	mark[s]=true;
	int temp=0;
	for (int i=0;i<next[s].size();i++)
		if (capacity[next[s][i]] > flow[next[s][i]])
			if (temp = dfs(end[next[s][i]],std::min(t,capacity[next[s][i]]-flow[next[s][i]])))
			{
				flow[next[s][i]]+=temp;
				return(temp);
			}
			for (int i=0;i<prev[s].size();i++)
				if (flow[prev[s][i]])
					if (temp=dfs(start[prev[s][i]],std::min(t,flow[prev[s][i]])))
					{
						flow[prev[s][i]]-=temp;
						return(temp);
					}
					return(0);
}


	void Flow::setDiv( std::vector <bool> A)
	{
		Div = A ;
	}

	std::vector <bool>  Flow::getDiv()
	{
		return Div ;
	}



	int Flow::maxFlow(int start,int end)
	{
		relax();
		destination=end;
		fill(mark.begin(),mark.end(),false);
		int ans=0,temp=0;
		while (temp=dfs(start,INF))
		{
			ans+=temp;
			Div=mark;
			fill(mark.begin(),mark.end(),false);
		}
		//dfs(start, INF ) ;
		setDiv(mark) ;
		return(ans);
	}

	Flow::Flow(int n)
	{
		destination=0;
		this->n=n;
		capacity.clear(); flow.clear(); start.clear(); end.clear(); next.clear(); prev.clear();
		mark.resize(n+1);
		next.resize(n+1);
		prev.resize(n+1);
	}
	void Flow::push_back(int left,int right,int weight)
	{
		capacity.push_back(weight);
		flow.push_back(0);
		start.push_back(left);
		end.push_back(right);
	}
