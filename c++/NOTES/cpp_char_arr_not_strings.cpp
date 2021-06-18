#include <iostream>
#include <vector>
#include <string>

/* Method suggested here is for char arr, where only the first given number of char are needed
   as input not string, since string does not respect size boundaries.*/

using namespace std;
int main()
{
 int n;
while(true){
 cout<<"Enter a number\n";
 cin>>n;
 cin.ignore();
/*Solution!!!!! cin.ignore() or other buffer clearing method has to be used to clear the buffer and take prompt to next line to be used by cin.get() or cin.getline(), if a previous input for some value had been taken.*/
 char c[n+1];
 string x;
/*size must be 1 more than word length for '\0' character, in both arr size
 declaration and in cin.get()!!!!!!*/

// cin.get(c,n+1);
// cout<<c<<endl;
/*NOT a GOOD choice, without cin.ignore() or other buffer clearing methods, if a previous input for some value was taken. Starts reading from the same line as the first input or prompt position,in this case from right beside n's input value, without even space. Same for cin.getline()
except cin.getline() is used to read lines and cin.get() is used to read char.*/

//cin>>c; //cin is good in the sense that it always starts reading from next line BUT!!!!!!
/* UNSAFE!!! does not respect array size, may use unallocated/corrupted memory in case of long string. READS till white space i.e only words NOT SENTENCES!! */

 /*for(int i=0;i<n;i++)
    cin>>c[i];
 c[n]='\0';*/
/*skips white spaces and does not stop reading until n characters inputted irrespective of wether enter is pressed or not!!! Best if exact length of WORD is known. Not at all good for sentences*/
// getline(cin,x); Only for strings!!! Different from cin.getline() which is for char arr.

char y[100];//temporary storage of maximum capacity!!! Best Method for looping input in char arr
 cin.getline(y,100);
 for(int i=0;i<n;i++)
     c[i] = y[i];
 c[n] = '\0';
 cout<<c<<endl;
}
 return 0;
}

