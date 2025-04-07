#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> intervals;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        intervals.emplace_back(l,r);
    }
    sort(intervals.begin(),intervals.end());
    string result;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            result+='0';

        }else
        {
            result+='1';
        }
    }
    cout<<result<<endl;
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> changes(100000,0);
    for(int i=0;i<n;i++)
    {
        int l,r,type;
        cin>>l>>r>>type;
        if(type==0)
        {
          changes[l]+=1;
        if(r+1<changes.size())
        {
            changes[r+1]-=1;
        }
        }else{
            changes[l]-=1;
            if(r+1<changes.size())
            {
                changes[r+1]+=1;
            }
        }
    }
    int fwbalance=0;
    for(int i=0;i<100000;i++)
    {
        fwbalance+=changes[i];
        if(fwbalance==0)
        {
            cout<<"0";
        }else if(fwbalance==1)
        {
            cout<<"0";
        }else if(fwbalance==-1)
        {
            cout<<"1";
        }
        
    }
    cout<<endl;
    return 0;
}*/