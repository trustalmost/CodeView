#include<iostream>
using namespace std;
class CNode
{
public:
	CNode *m_pNext;
	int m_Data;
	CNode()
	{
		m_pNext=NULL;
	}	
};
class CList
{
private:
	CNode *m_pHeader;
	int m_NodeSum;
public:
	CList()
	{
		m_pHeader=NULL;
		m_NodeSum=0;
	}
	CNode *MoveTrail()
	{
		CNode *pTmp=m_pHeader;
		for(int i=1;i<m_NodeSum;i++)
		{
			pTmp=pTmp->m_pNext;
		}
		return pTmp;
	}
	void AddNode(CNode *pNode)
	{
		if(m_NodeSum==0)
		{
			m_pHeader=pNode;
		}
		else
		{
			CNode *pTrail=MoveTrail();
			pTrail->m_pNext=pNode;
		}
		m_NodeSum++;
	}
	void chaxun(int n)
	{
		if(n>0&&n<=m_NodeSum)
		{
			CNode *pTmp=m_pHeader;
			for(int i=0;i<n-1;i++)
			{
				pTmp=pTmp->m_pNext;
			}
			cout<<pTmp->m_Data<<endl;
		}
	}
	void del(int n)
	{
		CNode *p=m_pHeader;
		if(n==1) m_pHeader=m_pHeader->m_pNext;
		for(int i=1;i<n-1;i++)
		{
			p=p->m_pNext;
		}
		p->m_pNext=p->m_pNext->m_pNext;
		m_NodeSum--;
	}
	void PassList()
	{
		if(m_NodeSum>0)
		{
			CNode *pTmp=m_pHeader;
			cout<<pTmp->m_Data<<" ";
			for(int i=1;i<m_NodeSum;i++)
			{
				pTmp=pTmp->m_pNext;
				cout<<pTmp->m_Data<<" ";
			}
		}
	}
	~CList()
	{
		if(m_NodeSum>0)
		{
		CNode *pDelete=m_pHeader;
		CNode *pTmp=NULL;
		for(int i=0;i<m_NodeSum;i++)
		{
			pTmp=pDelete->m_pNext;
			delete pDelete;
			pDelete=pTmp;
		}
		m_NodeSum=0;
		pDelete=NULL;
		pTmp=NULL;
 	   }
 	m_pHeader=NULL;
   }
};
int main()
{
	CList list;
	int a=1;
	for(int i=0;a!=0;i++)
	{
		CNode *pNode=new CNode();
		cin>>a;
		pNode->m_Data=a;
		list.AddNode(pNode);
	}
	cout<<endl;
	int m,n;
	cin>>n>>m;
	list.chaxun(n);
	list.del(m);
	list.PassList();
	return 0;
}
