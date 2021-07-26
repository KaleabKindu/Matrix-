#include <iostream>
#include <iomanip>
using namespace std;

class Matrix
{
public:
    float fmat[3][3];
public:
     Matrix(float arg[3][3]);
    int det(float arg[3][3]);
    void inv(float arg[3][3]);
    void adj(float arg[3][3]);
    void tran(float arg[3][3]);
    void disp(float arg[3][3]);
    void cof(float arg[3][3]);
    Matrix operator+(Matrix);
    Matrix operator*(Matrix);
    Matrix operator-(Matrix);
    Matrix operator=(Matrix);
};
 Matrix::Matrix(float argg[3][3])
{

    for (int i=0; i<=2; i++)
    {
        for (int b=0; b<=2; b++)
        {
           fmat[i][b]=argg[i][b];
        }
    }
}
int Matrix::det(float arg[3][3])
{
    int det;
    det=(arg[0][0]*arg[1][1]*arg[2][2]) - (arg[0][0]*arg[2][1]*arg[1][2])-(arg[2][2]*arg[0][1]*arg[1][0])-(arg[0][2]*arg[1][1]*arg[2][0])+(arg[0][2]*arg[1][0]*arg[2][1])+(arg[2][0]*arg[0][1]*arg[2][2]);
   return det;
}
void Matrix::tran(float arg[3][3])
{
    float tmp[3][3];
    for (int i=0; i<=2; i++)
    {
        for (int b=0; b<=2; b++)
        {
            tmp[b][i]=arg[i][b];
        }
    }
    disp(tmp);
}
void Matrix::disp(float arg[3][3])
{
    for (int i=0; i<=2; i++)
    {
        for (int b=0; b<=2; b++)
        {
            cout<<setw(4)<<arg[i][b]<<" ";
        }
        cout<<endl;
    }
}
void Matrix::cof(float arg[3][3])
{
    float temp[3][3];
    temp[0][0]=(arg[1][1]*arg[2][0])-(arg[1][0]*arg[2][1]);
    temp[0][1]=(arg[1][2]*arg[2][0])-(arg[1][0]*arg[2][2]);
    temp[0][2]=(arg[1][0]*arg[2][1])-(arg[2][0]*arg[1][1]);
    temp[1][0]=(arg[2][1]*arg[0][2])-(arg[0][1]*arg[2][2]);
    temp[1][1]=(arg[2][2]*arg[0][0])-(arg[0][2]*arg[2][0]);
    temp[1][2]=(arg[2][0]*arg[0][1])-(arg[0][0]*arg[2][1]);
    temp[2][0]=(arg[0][1]*arg[1][2])-(arg[1][1]*arg[0][2]);
    temp[2][1]=(arg[0][2]*arg[1][0])-(arg[2][2]*arg[0][0]);
    temp[2][2]=(arg[0][0]*arg[1][1])-(arg[1][0]*arg[0][1]);
    disp(temp);
}
void Matrix::adj(float arg[3][3])
{
    float temp[3][3];
    temp[0][0]=(arg[2][0]*arg[1][1])-(arg[1][0]*arg[2][1]);
    temp[0][1]=(arg[1][2]*arg[2][0])-(arg[1][0]*arg[2][2]);
    temp[0][2]=(arg[1][0]*arg[2][1])-(arg[2][0]*arg[1][1]);
    temp[1][0]=(arg[2][1]*arg[0][2])-(arg[0][1]*arg[2][2]);
    temp[1][1]=(arg[2][2]*arg[0][0])-(arg[0][2]*arg[2][0]);
    temp[1][2]=(arg[2][0]*arg[0][1])-(arg[0][0]*arg[2][1]);
    temp[2][0]=(arg[0][1]*arg[1][2])-(arg[1][1]*arg[0][2]);
    temp[2][1]=(arg[0][2]*arg[1][0])-(arg[2][2]*arg[0][0]);
    temp[2][2]=(arg[0][0]*arg[1][1])-(arg[1][0]*arg[0][1]);
    float tmp[3][3];
    for (int i=0; i<=2; i++)
    {
        for (int b=0; b<=2; b++)
        {
            tmp[b][i]=temp[i][b];
        }
    }
    disp(tmp);
}
void Matrix::inv(float arg[3][3])
{
    int det;
    det=(arg[0][0]*arg[1][1]*arg[2][2]) - (arg[0][0]*arg[2][1]*arg[1][2])-(arg[2][2]*arg[0][1]*arg[1][0])-(arg[0][2]*arg[1][1]*arg[2][0])+(arg[0][2]*arg[1][0]*arg[2][1])+(arg[2][0]*arg[0][1]*arg[2][2]);
    float temp[3][3];
    temp[0][0]=(arg[1][1]*arg[2][0])-(arg[1][0]*arg[2][1]);
    temp[0][1]=(arg[1][2]*arg[2][0])-(arg[1][0]*arg[2][2]);
    temp[0][2]=(arg[1][0]*arg[2][1])-(arg[2][0]*arg[1][1]);
    temp[1][0]=(arg[2][1]*arg[0][2])-(arg[0][1]*arg[2][2]);
    temp[1][1]=(arg[2][2]*arg[0][0])-(arg[0][2]*arg[2][0]);
    temp[1][2]=(arg[2][0]*arg[0][1])-(arg[0][0]*arg[2][1]);
    temp[2][0]=(arg[0][1]*arg[1][2])-(arg[1][1]*arg[0][2]);
    temp[2][1]=(arg[0][2]*arg[1][0])-(arg[2][2]*arg[0][0]);
    temp[2][2]=(arg[0][0]*arg[1][1])-(arg[1][0]*arg[0][1]);
    float tmp[3][3];
    for (int i=0; i<=2; i++)
    {
        for (int b=0; b<=2; b++)
        {
            tmp[b][i]=(temp[i][b])/det;
        }
    }
    disp(tmp);
}
Matrix Matrix::operator+(Matrix temp)
{
    float res[3][3];
for(int i=0; i<=2; i++)
{
    for (int b=0; b<=2; b++)
    {
      res[i][b]=temp.fmat[i][b] + fmat[i][b];
    }
}
Matrix resd(res);
return resd;
}
Matrix Matrix::operator-(Matrix temp)
{
    float res[3][3];
for(int i=0; i<=2; i++)
{
    for (int b=0; b<=2; b++)
    {
      res[i][b]=fmat[i][b] - temp.fmat[i][b];
    }
}
Matrix ress(res);
return ress;
}
Matrix Matrix::operator*(Matrix temp)
{
   float res[3][3];
for(int i=0; i<=2; i++)
{
    for (int b=0; b<=2; b++)
    {
          res[i][b]=(fmat[i][0]*temp.fmat[0][b])+(fmat[i][1]*temp.fmat[1][b])+(fmat[i][2]*temp.fmat[2][b]);
    }
}
Matrix resm(res);
return resm;
}
Matrix Matrix::operator=(Matrix temp)
{
    Matrix res(temp.fmat);
    return res;
}
