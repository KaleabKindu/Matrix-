#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int num;
cout<<"**********A Program that Multiplies Any Two Square Matrices************** \n";
cout<<"Enter the Dimension of the Square Matrix: ";
    cin>>num;
    int **mat = new int*[num]; 
for (int i = 0; i < num; ++i)
    mat[i] = new int[num];
    int **maat = new int*[num]; 
for (int i = 0; i < num; ++i)
    maat[i] = new int[num];
    int **mul = new int*[num];
for (int i=0; i<num; ++i)
    mul[i]=new int[num];
cout<<"Enter Elements of The First Matrix: \n";
        for(int i=0; i<num; i++)
        {    for (int b=0; b<num; b++)
                 cin>>*(*(mat+i)+b);
        }

    cout<<"Enter Elements of The Second Matrix: \n";
        for(int i=0; i<num; i++)
        {    for (int b=0; b<num; b++)
                 cin>>*(*(maat+i)+b);
        }
    for(int i=0; i<num; i++)
    {
        for(int b=0; b<num; b++)
        {   int sum=0;
            for(int c=0; c<num; c++)
            {
                sum+=(*(*(mat+i)+(c))) * (*(*(maat+c)+b));    // same as sum+=mat[i][c]*maat[c][b]
            }
            *(*(mul+i)+b)=sum;
        }
    }
        cout<<"The Multiple of The Square Matrices You Entered is: \n";
        for(int i=0; i<num; i++)
        {    for (int b=0; b<num; b++)
                 cout<<setw(4)<<*(*(mul+i)+b)<<" ";
            cout<<endl;
        }
    return 0;
}
