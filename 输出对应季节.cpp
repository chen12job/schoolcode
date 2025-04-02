#include<bits/stdc++.h>
using namespace std;
string getSeason(int month){
    if(month>=3 && month<=5)
    {
        return "spring";
    }else if(month>=6 &&month<=8)
    {
        return "summer";
    }else if(month>=9 && month<=11)
    {
        return  "autumn";
    }else 
    {
        return "winter";
    }
}

int main()
{
    string input;
    cin>>input;
    //月份
    string monthStr=input.substr(4,2);
    int month=stoi(monthStr);
    string season=getSeason(month);
    cout<<season<<endl;
    return 0;
}