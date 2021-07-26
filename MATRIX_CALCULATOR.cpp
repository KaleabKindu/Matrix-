#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
    float matt[3][3];
    float maat[3][3];
    int choice;
  cout<<"    This is Matrix Calculator choose any operation\n"
      <<"1. choose one for a single matrix operation"<<endl
      <<"2. choose two for two matrix operation"<<endl
      <<"Choice: ";
  cin>>choice;
  if (choice==1)
  {
        cout<<"enter elements: \n";
        cin>>maat[0][0]>>maat[0][1]>>maat[0][2]
           >>maat[1][0]>>maat[1][1]>>maat[1][2]
           >>maat[2][0]>>maat[2][1]>>maat[2][2];
      
    int ch;
    cout<<"choose any operation: \n"
        <<"1. Determinant           2. Adjoint\n"
        <<"3. Inverse               4. Transpose\n"
        <<"5. cofactor\n"
         <<"Choice: ";
    cin>>ch;
    Matrix matr(maat);
    if (ch==1)
    {
      int res=matr.det(maat);
      cout<<res<<endl;
    }
    else if (ch==2)
        matr.adj(maat);
    else if (ch==3)
        matr.inv(maat);
    else if (ch==4)
        matr.tran(maat);
    else if (ch==5)
        matr.cof(maat);
    else
        cout<<"wrong input.....try again!!!";

  }
  else if (choice==2)
  {
        cout<<"enter elements of the first matrix: \n"
        cin>>maat[0][0]>>maat[0][1]>>maat[0][2]
           >>maat[1][0]>>maat[1][1]>>maat[1][2]
           >>maat[2][0]>>maat[2][1]>>maat[2][2];
        cout<<"enter elements of the second matrix: \n"
        cin>>matt[0][0]>>matt[0][1]>>matt[0][2]
           >>matt[1][0]>>matt[1][1]>>matt[1][2]
           >>matt[2][0]>>matt[2][1]>>matt[2][2];
    
Matrix matrr(matt);
Matrix matr(maat);
int chy;
cout<<"choose an operation: \n"
    <<"1. Addition            2. Substraction\n"
    <<"3. Multiplication \n"
    <<"Choice: ";
cin>>chy;
if (chy==1)
{
     Matrix mar = matr + matrr;
     mar.disp(mar.fmat);
}
else if (chy==2)
    {
     Matrix mar = matr - matrr;
     mar.disp(mar.fmat);
    }
else if (chy==3)
    {
     Matrix mar = matr * matrr;
     mar.disp(mar.fmat);
    }

  else
    cout<<"wrong input";
    }
}
