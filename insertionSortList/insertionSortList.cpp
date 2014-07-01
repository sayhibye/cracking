#include<iostream>
#include<string>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
	ListNode *insertionSortList(ListNode *head)
	{
		if(head==NULL)
			return NULL;
		if(head->next==NULL)
			return head;

		ListNode *cur=head->next;
		head->next=NULL;
		ListNode *p=cur->next;

		while(cur!=NULL)
		{
			if(cur->val<=head->val)
			{
				cur->next=head;
				head=cur;
			}
			else
			{
				ListNode *pre=head;
				while(pre->next!=NULL && pre->next->val<cur->val)
					pre=pre->next;

				if(pre->next==NULL)
				{
					cur->next=NULL;
					pre->next=cur;
				}
				else
				{
					cur->next=pre->next;
					pre->next=cur;
				}

			}

			cur=p;
			if(p==NULL)
				break;
			else
			    p=p->next;
		}
		return head;
	}
};

int main()
{
	ListNode *head=new ListNode(3);
	head->next=NULL;
	ListNode *pre=head;
	/*for(int i=0;i<4;i++)
	{
		ListNode *p=new ListNode(5-i-1);
		p->next=NULL;
		pre->next=p;
		pre=p;
	}*/
	ListNode *p=new ListNode(4);
	pre->next=p;
	pre=p;
	ListNode *q=new ListNode(1);
	pre->next=q;
	pre=q;

	Solution S;
	head=S.insertionSortList(head);

	for(pre=head;pre!=NULL;pre=pre->next )
		cout<<pre->val;

	system("pause");
	return 0;
}