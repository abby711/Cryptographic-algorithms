// Online C++ compiler to run C++ program online
#include <iostream>
#include<string>
using namespace std;
int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    string mess;
    string cipher="";
    int key;
    cout<<"Message ";
    cin>>mess;
    cout<<"Key ";
    cin>>key;
    for(int i=0;i<mess.size();i++){
        if(mess[i]>='a' && mess[i]<='z'){
            int ascii=mess[i];
            ascii=ascii-97;
            ascii=ascii+key;
            ascii=ascii%26;
            ascii=ascii+97;
            char c=ascii;
            cipher+=c;
        }
        else{
            int ascii=mess[i];
            ascii=ascii-65;
            ascii=ascii+key;
            ascii=ascii%26;
            ascii=ascii+65;
            char c=ascii;
            cipher+=c;
        }
    }
    cout<<cipher;

    return 0;
}
