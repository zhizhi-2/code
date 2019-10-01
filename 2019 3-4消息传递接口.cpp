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
int status[maxn] ;//����ÿ�����̵�״̬,ÿ���������һ��ָ��ý�����0�������Ѹ��£����ʵ�һ��������1�����ѷ���
int run(int cur)
{
	status[cur]=1;//������1
	if(g[cur].size()==0) return 0;
	int dest=g[cur][0].no;
	if(g[dest].size()==0||status[dest]==1) return -1;//��Ҫ���ʵķ��ʵĽ���û��ָ��������һ����ǰ���ʹ���ָ��˵����һ����ѭ���Ӷ��γ�����
	   if(g[cur][0].op!=g[dest][0].op&&g[dest][0].no==cur)
		{
			g[cur].erase(g[cur].begin());
			g[dest].erase(g[dest].begin());
			status[cur]=0,status[dest]=0; //����ָ����0
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
	for(int i=0;i<n;i++) //�����ֺ���ĸ���з���
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
			p.op=b[0]; //����Ҫ�������ո��������� 
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
		if(run(i)==-1) //��������
		{
			flag=1;
			break;
		}
	}
	 cout<<flag<<endl;
 } 
}

