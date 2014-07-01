#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
public:
	void reverseWords(string &s)
	{
		if(s.empty())
			return;

		int len=s.size();
		reverse(s,0,len-1);

		int start=0,end=0;
		while(end<=len)
		{
			if(s[end]==' '|| s[end]=='\0')
			{
				reverse(s,start,end-1);
				start=end+1;
			}
			end++;
		}
	}

private:
	void reverse(string &s,int start,int end)
	{
    	while(start<end)
		{
			char temp=s[start];
			s[start]=s[end];
			s[end]=temp;

			start++;
			--end;
		}
	}
};

int main()
{
	string s=" ";
	Solution S;
	S.reverseWords(s);

	cout<<s<<endl;

	system("pause");
	return 0;
}