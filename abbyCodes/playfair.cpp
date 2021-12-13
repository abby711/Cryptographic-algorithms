// Online C++ compiler to run C++ program online
#include <iostream>
#include<string>
#include<vector>
using namespace std;
char keyMatrix[5][5];
int count[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void setMatrix(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            keyMatrix[i][j]=' ';
        }
    }
}



vector<int> findIndex(char ch){
    vector<int> index;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if (keyMatrix[i][j]==ch)
            {
                index.push_back(i);
                index.push_back(j);
                return index;
            }
             
        }
    }
}
int main() {
    string key,pt;
    cin>>key;
    cin>>pt;
    int temp,temp2;
    setMatrix();
    int index=0;

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(key[index]=='i' || key[index]=='j')
            {
                temp=key[index]-97;
                if(key[index]=='i' )
                   temp2=temp+1;  
                else
                   temp2=temp-1;
                
                if(count[temp]==0 && count[temp2]==0) 
                    { count[temp]=1; 
                      count[temp2]=1;
                      keyMatrix[i][j]='i';
                      index++;
                    }
            }
            else{
                 temp=key[index]-97;
                if(count[temp]==0) 
                    { count[temp]=1; 
                      
                      keyMatrix[i][j]=key[index];
                      index++;
                    }
            }
            
        }
    }
    char ch;
    int flag=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            
            if(keyMatrix[i][j]==' ')
            {   flag=0;
                for(int k=0;k<26 && flag!=1;k++)
                 {
                    
                     if (count[k]==0)
                     {
                       if(k==13 || k==14)
                     {
                        if (count[13]==0 && count[14]==0)
                        {
                         ch=char(k+97);
                         count[13]=0;
                         count[14]=0;
                         keyMatrix[i][j]='i';
                         flag=1;
                       
                        }
                    } 
                     else
                     {
                       int l=k+97;
                       ch=l;
                       count[k]=0;
                       keyMatrix[i][j]=ch;
                       flag=1;
                     }
                }
                     else
                      continue;
                       
                 }
                }
            }
        }
    
    
    for(int i=0;i<5;i++){
        cout<<endl;
        for(int j=0;j<5;j++)
        cout<<keyMatrix[i][j]<<" ";
    
    
    

}
return 0;
}
