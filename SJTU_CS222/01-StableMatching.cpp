/*
Sample 1:
Input:
5
1 0 3 4 2
3 1 0 2 4
1 4 2 3 0
0 3 2 1 4
1 3 0 4 2

4 0 1 3 2
2 1 3 0 4
1 2 3 4 0
0 4 3 2 1
3 1 4 2 0

Output:
0-0
1-2
2-1
3-4
4-3

*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MaxM = 20;
int M;
int male[MaxM][MaxM];
int female[MaxM][MaxM];

set<pair<int,int>> GS(){ //(int male[][MaxM], int female[][MaxM], int M){
	set<pair<int,int>> s;
	set<pair<int,int>>::iterator it;
	int w;
	vector<bool> isMatch;
	for(int i = 0; i<M; i++){
		isMatch.push_back(false);
	}
	int cnt = 0;
	while(cnt!=M){
		for(int m = 0; m < M; m++){
			for(int f = 0; f < M; f++){
				if(isMatch[m]==true){
					break;
				}
				else if(isMatch[m]==false)
				{
					w = male[m][f];
					if(s.empty()){
						s.insert(make_pair(m,w));
						isMatch[m] = true;
						cnt++;
					}
					else{
						for(it=s.begin ();it!=s.end ();it++)
					    {
					        if((*it).second == w){
					        	int m1 = (*it).first;
					        	int i;
					        	for(i = 0; i<M;i++){
					        		if(female[w][i]==m1 || female[w][i]==m){
					        			break;
					        		}
					        	}
					        	if(female[w][i]==m){
					        		s.erase(it);
					        		isMatch[m1] = false;
					        		s.insert(make_pair(m,w));
					        		isMatch[m] = true;
					        	}
					        	break;
					        }
					    }
					    if(it == s.end()){
					    	s.insert(make_pair(m,w));
					    	isMatch[m] = true;
					    	cnt++;
					    }
					}
				}
			}
		}
			
	}
	return s;
}
int main() {
	// your code goes here
	cin>>M;
	// input preference
	for(int m = 0; m<M; m++)
	{
		for(int f = 0; f < M; f++)
		{
			cin>>male[m][f];
		}
	}
	
	for(int m = 0; m<M; m++)
	{
		for(int f = 0; f < M; f++)
		{
			cin>>female[m][f];
		}
	}
	set<pair<int,int>> s = GS();
	set<pair<int,int>>::iterator it;
	for(it=s.begin ();it!=s.end ();it++)
	{
		cout<<(*it).first<<"-"<<(*it).second<<endl;
	}
	return 0;
}
