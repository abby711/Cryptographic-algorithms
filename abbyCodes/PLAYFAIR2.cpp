#include<iostream>
using namespace std;
int main()
{
int i,j,isI=0,l,k=0,start=0,same=0,k1=0;
int i1,j1,i2,j2,i11,jj;
char alph[5][5],chr[25],chr2[25],character,chr1='a',chr_ex[25];
char txt[25],txt2[25];
cout<<"Enter the text : ";
cin>>chr;
for(i=0;i<strlen(chr2);i++) /*TO PREVENT STRING FROM BEING PRINTED WITH
GARBAGE CHARACTER...*/
{
chr_ex[i]='-';
}
for(i=0;i<strlen(chr);i++)
{
cout<<"\n"<<i+1<<"\t"<<chr[i];
chr_ex[i]=chr[i];
}
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
alph[i][j]='-';
}
}
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
character=chr[++k];
for(l=k-1;l>=0;l--) //FOR REPEATING CHARACTERS...
{
if(character==chr[l])
{
chr[k]='-';
break;
}
}
}
}
k=0;
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
if(start++<strlen(chr))
if(chr[k]!='-') //FOR i AND j
{
if(chr[k]=='i' || chr[k]=='j')
{
if(isI==0)
{
alph[i][j]=chr[k];
isI=1;
}
else
{
if(chr[k]=='i') chr[k]='i';
if(chr[k]=='j') chr[k]='j';
j--;
}
}
else alph[i][j]=chr[k];
}
else
{
chr[k]='-';
j--;
}
k++;
}
}
chr1--;
k1=0;
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
if(alph[i][j]=='-')
{
same=0;
chr1++;
for(k1=0;k1<strlen(chr);k1++)
{
if(chr1==chr[k1])
{
same=1; //else same=0;
j--;
break;
}
}
if(same!=1)
{
if(chr1=='i' || chr1=='j')
{
if(isI==0)
{
alph[i][j]=chr1;
isI=1;
}
else
j--;
}
else
alph[i][j]=chr1;
}
}
}
}
cout<<"\n"<<"\n"<<"\n";
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
cout<<alph[i][j];
}
cout<<"\n";
}
j=0;
for(i=0;i<strlen(chr);i++)
{
if(chr[i]=='-')
{
for(j=i;j<strlen(chr);j++)
{
chr[j]=chr[j+1];
}
}
}
cout<<"\n"<<"\n"<<"Enter the plain text : ";
cin>>txt;
j=0;
for(i=0;i<strlen(txt);i++)
{
txt2[j++]=txt[i];
if(txt[i]==txt[i+1])
{
txt2[j++]='x';
}
}
jj=j;
for(i11=0;i11<strlen(txt2);i11+=2)
{
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
if(txt2[i11]==alph[i][j])
{
i1=i;
j1=j;
}
if(txt2[i11+1]==alph[i][j])
{
i2=i;
j2=j;
}
}
}
if(i1==i2)
{
if((j1+1)>=5) j1=-1;
if((j2+1)>=5) j2=-1;
txt2[i11]=alph[i1][j1+1];IT8761- Security Lab 2021-2022
St. Joseph’s College of Engineering
txt2[i11+1]=alph[i2][j2+1];
}
else if(j1==j2)
{
if((i1+1)>=5) i1=-1;
if((i2+1)>=5) i2=-1;
txt2[i11]=alph[i1+1][j1];
txt2[i11+1]=alph[i2+1][j2];
}
else
{
if(i2>i1)
{
txt2[i11+1]=alph[i2][j1];
txt2[i11]=alph[i1][j2];
}
else
{
txt2[i11]=alph[i2][j1];
txt2[i11+1]=alph[i1][j2];
}
}
}
cout<<"\n"<<"Final string : ";
for(i=0;i<jj;i++)
{
cout<<txt2[i];
}
}
