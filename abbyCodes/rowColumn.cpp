// Online C++ compiler to run C++ program online
#include <iostream>
#include<string>
using namespace std;
int main() {
    // Write C++ code here
    char a='A';
    int x=a;
    cout<<x;
    char b=x;
    cout<<b;
    int d;
    string pt;
    cin>>d;
    cin>>pt;
    int c=pt.size()/d;
    if (pt.size()%2!=0) c++;
    char cipher[d][c];
    int i=0,j,k=0;
    for(int i=0;i<d;i++){
        for(int j=0;j<c;j++)
        
         cipher[i][j]='\0';
    }

    for(int j=0;j<c && k<=pt.size();j++)
    {
        for(int i=0;i<d && k<=pt.size();i++){
            cipher[i][j]=pt[k];
            k++;
        }
        
        
    }
    string res="";
    for(int i=0;i<d;i++){
        for(int j=0;j<c;j++)
        if(cipher[i][j]!='\0') res+=cipher[i][j];
    }
    cout<<res;
    string res2="";
    for(int j=0;j<c;j++){
        for(int i=0;i<d;i++)
        if(cipher[i][j]!='\0') res2+=cipher[i][j];
    }
  cout<<res2;

    return 0;
}
