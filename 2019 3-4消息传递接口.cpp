#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
struct progress
{
	int no;
	char op;
};
const int maxn=10005;
vector<progress> g[maxn];
int status[maxn] ;//设置每个进程的状态,每个进程完成一个指令将该进程置0，代表已更新，访问到一个进程置1代表已访问
int run(int cur)
{
	status[cur]=1;//访问置1
	if(g[cur].size()==0) return 0;
	int dest=g[cur][0].no;
	if(g[dest].size()==0||status[dest]==1) return -1;//若要访问的访问的进程没有指令或访问了一个以前访问过的指令说明是一个死循环从而形成死锁
	   if(g[cur][0].op!=g[dest][0].op&&g[dest][0].no==cur)
		{
			g[cur].erase(g[cur].begin());
			g[dest].erase(g[dest].begin());
			status[cur]=0,status[dest]=0; //消除指令置0
			return 0;
		}
		else
		{
			run(dest);
		}
		run(cur);
}
int main()
{
	int t,n;
	cin>>t>>n;
	getchar(); 
	while(t--)
	{
	string str;
	for(int i=0;i<n;i++) g[i].clear();
	for(int i=0;i<n;i++) //把数字和字母进行分离
	{
		getline(cin,str);
		string b="";
		progress p;
		for(int j=0;str[j];j++)
		{
			if(str[j]==' ')
			{
				p.op=b[0];
				p.no=0;
				for(int k=1;b[k];k++)
				{
					p.no*=10;
					p.no+=(b[k]-'0');
				}
				g[i].push_back(p);
				b="";
			}
			else 
			{
				b+=str[j];
			}
		   }
			p.op=b[0]; //结束要像遇到空格那样处理 
			p.no=0;
			for(int k=1;b[k];k++)
			{
				p.no*=10;
				p.no+=(b[k]-'0');
			}
			g[i].push_back(p);
			b="";
	}
	memset(status,0,sizeof(status));
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(run(i)==-1) //遇到死锁
		{
			flag=1;
			break;
		}
	}
	 cout<<flag<<endl;
 } 
}

