// Online C++ compiler to run C++ program online
#include <iostream>
#include<string>
using namespace std;
char keyM[5][5];
int coun[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void setMatrix(){
    for(int i=0;i<5;i++)
    for(int j=0;j<5;j++) keyM[i][j]='\0';
}
int main() {
    // Write C++ code here
    setMatrix();
    string key,pt;
    cin>>key;
    cin>>pt;
    int index=0,x;
    for(int i=0;i<5 && index<key.length();i++)
    for(int j=0;j<5 && index<key.length();j++)
    {
        
        x=key[index];
        x=x-97;
        if(coun[x]==0)
        {
            if(x==8 || x==9)
            {
                coun[8]=1;
                coun[9]=1;
                keyM[i][j]='i';
                index++;

            }
            else{
            keyM[i][j]=key[index];
            coun[x]=1;
            index++;
            }
            
        }
        else if(coun[x]==1)
           index++;
        
        
    }
    index=0;
    int flag=0;
    
    for(int i=0;i<5 && index<26;i++)
    for(int j=0;j<5 && index<26;j++)
    {   
        flag=0;
        if(keyM[i][j]=='\0')
        {   
            for(int j=0;j<26 && flag==0;j++)
        {
            index=j;
            if(coun[index]==0)
            {
                if (index==8 || index==9){
                    coun[8]=1;
                    coun[9]=1;
                    keyM[i][j]='i';
                    index++;
                    flag=1;
                    
                }
                else{
                    coun[index]=1;
                    int x=index+97;
                    char ch=x;
                    keyM[i][j]=ch;
                    index++;
                    flag=1;
                    
                }
            }
            
        }
    }
    }
    
    
    for(int i=0;i<5;i++){
        cout<<endl;
    
    for(int j=0;j<5;j++)
    cout<<keyM[i][j]<<" ";
    }
    
    return 0;
}
