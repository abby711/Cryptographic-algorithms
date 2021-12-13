// Online C++ compiler to run C++ program online
#include <iostream>
#include<string>
using namespace std;
int main() {
    string key,pt;
    cin>>key;
    cin>>pt;
    int lK=key.size();
    int lPt=pt.size();
    int k[3][3],p[3][1],index=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int temp=key[index];
            temp=temp-97;
            k[i][j]=temp;
            index++;
        }
    }
    index=0;
    for(int i=0;i<3;i++)
    {
            int temp=pt[index];
            temp=temp-97;
            p[i][0]=temp;
            index++;
    }
    cout<<"\nKey matrix "<<endl;
    for(int i=0;i<3;i++){
        cout<<endl;
        for(int j=0;j<3;j++)
        cout<<k[i][j]<<" ";
    }
    cout<<"\nPlain text matrix "<<endl;
    for(int i=0;i<3;i++){
        cout<<endl;
        
        cout<<p[i][0];
    }
    
    int cipher[3][1],i,j,l;
    for(i=0;i<3;i++)
    {
        for(j=0;j<1;j++)
        {
            cipher[i][j]=0;
            for(l=0;l<3;l++)
              cipher[i][j]+=k[i][l]*p[l][j];
        }
    }
    string res="";
    cout<<"\nCipher text matrix "<<endl;
    for(i=0;i<3;i++){
        cout<<endl;
        cipher[i][0]%=26;

        cout<<cipher[i][0];
        int temp=cipher[i][0]+97;
        char ch=temp;
        res+=ch;
        
    }
    cout<<"\nCipher text "<<res;
    return 0;
}
