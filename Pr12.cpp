//In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[].
//Write C++ program using stack to check whether given expression is well parenthesized or not.
#include <iostream>
#include<string.h>
using namespace std;
int max=20;
struct stack
{
 int top;
 int array[20];
}st;
void initialize()
{ st.top=-1;}
bool isfull()
{
 if(st.top>=19)
 { return 1; }
 else
 { return 0; }
}
bool isempty()
{
 if(st.top=-1)
 { return 1; }
 else
 { return 0; }
}
void push(int num)
{
 if(isfull())
 { cout<<"stack is full"<<endl; }
 else
 {
  st.array[st.top+1]=num;
  st.top++;
 }
}
int pop()
{
 if(isempty())
 { cout<<"stack is empty..\n"; }
 else
 {
  st.top=st.top-1;
  return st.array[st.top+1];
 }
}

int main() 
{ 
 string inputstring, c;
 int i,length;
 initialize();
 cout<<"enter a string of paranthesis \n";
 cin>>inputstring;
 length=inputstring.length();
 for(i=0;i<length;i++)
 {
  if(inputstring[i]=='{')
  push(inputstring[i]);
  else if(inputstring[i]=='}')
  pop();
  else
  {
    printf("Error : Invalid character !!\n");
    return 0;
  }
 }
 if(isempty())
 printf("Valid Paranthesis Expression\n");
 else
 printf("Invalid Paranthesis Expression\n");
 return 0;
}

