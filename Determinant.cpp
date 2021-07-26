#include <iostream>
//#include <cmath>
//#include <iomanip>

using namespace std;
int dett(int** , int);

int main()
{
    int sz;
    cin>>sz;
    int **(mat)= new int*[sz];
    for(int i=0; i<sz; i++)
      mat[i]= new int[i];
    cout<<"enter the elements of the matrix; \n";
    for (int i=0; i<sz; i++)
    {
        for(int b=0; b<sz; b++)
        {
            cin>>*(*(mat+i)+b);
        }
    }
    cout<<dett(mat,sz);
}
int dett(int** sth, int n)
{
    int det=0;
    if(n==2)
    {
      det+=*(*(sth)) * *(*(sth+1)+1) - *(*(sth+1)) * *(*(sth)+1);
    }
    else
    {
      for(int i=0; i<n; i++)
      {
          for (int b=0; b<n; b++)
          {
              if ((i+b)%2==0)
                 det+=(*(*(sth+i)+b)) * dett(sth+i,n-1);
              else
                det+=0-(*(*(sth+i)+b)) * dett(sth+i,n-1);
          }
      }  
    }
   
      return det;
}
