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
    string key;
    string pt;
    cin>>key;
    cin>>pt;
    string cipher="";
    int i=0,j=0;
    while(i<key.size() && j<pt.size()){
    
            int kIndex=key[i]-97;
            int pIndex=pt[j]-97;
            int value=kIndex+pIndex;
            value=value%26;
            value+=97;
            char x=value;
            cipher+=x;
            i++;
            j++;
            
        
    }
    i=0;
    j=0;
    
    cout<<cipher<<endl;
    string decipher="";
    while(i<key.size() && j<cipher.size()){
    
            int kIndex=key[i]-97;
            int pIndex=cipher[j]-97;
            int value;
            if(pIndex>kIndex)
              value=pIndex-kIndex;
            else
                 value=kIndex-pIndex;

            value=value%26;
            value+=97;
            char x=value;
            decipher+=x;
            i++;
            j++;
            
        
    }
    cout<<decipher;

    return 0;
}
