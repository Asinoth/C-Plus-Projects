#include "std_lib_facilities.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

class Matrix3 //the class of the matrix  3X3
{

    public:
      void fill(bool option) //fill the matrix with 0
      {
        if(option==0)
        {
          for(int i=0; i<=2; i++)
          {
            for(int j=0; j<=2; j++)
            {
                  matrix[i][j]=0;
            }
          }
        }

            if(option==1) // fill the matrix with random numbers
            {
                srand(time(NULL));
             for(int i=0; i<=2; i++)
               {
                for(int j=0; j<=2; j++)
                {
                    matrix[i][j]=rand() % 100;
                }
               }
          }
        }

        void fill(int x1, int x2, int x3, int y1, int y2, int y3, int z1, int z2, int z3)
        {
            matrix[0][0] = x1;
            matrix[1][0] = x2;
            matrix[2][0] = x3;
            matrix[0][1] = y1;
            matrix[1][1] = y2;
            matrix[2][1] = y3;
            matrix[0][2] = z1;
            matrix[1][2] = z2;
            matrix[2][2] = z3;
        } // the points of the matrix




        Matrix3 operator-(Matrix3 other) //subtraction
        {
            Matrix3 result;
            for(int i=0; i<=2; i++)
            {
                for(int j=0; j<=2; j++)
                {
                    result.matrix[i][j]=matrix[i][j] - other.matrix[i][j];
                }
            }
            return result;
        }



        Matrix3 operator+(Matrix3 other) //addition
        {
            Matrix3 result;
            for(int i=0; i<=2; i++)
            {
                for(int j=0; j<=2; j++)
                {
                    result.matrix[i][j]=matrix[i][j] + other.matrix[i][j];
                }
            }
            return result;
        }



        Matrix3 operator*(Matrix3 other) //multiply with other matrix
        {
            Matrix3 result;
            for(int i=0; i<=2; i++)
            {
                for(int j=0; j<=2; j++)
                {
                    result.matrix[i][j]=matrix[i][j] * (other.matrix[1][j]+other.matrix[2][j]+other.matrix[3][j]);
                }
            }
            return result;
        }

        Matrix3 operator*(int c) //multiply with c
        {
            Matrix3 result;
            for(int i=0; i<=2; i++)
            {
                for(int j=0; j<=2; j++)
                {
                    result.matrix[i][j]=matrix[i][j] * c;
                }
            }
            return result;
        }


        friend ostream& operator<<(ostream &os, Matrix3 other) //show the matrix
        {
            os << other.matrix[0][0] << ' ' << other.matrix[1][0] << ' ' << other.matrix[2][0] << endl
               << other.matrix[0][1] << ' ' << other.matrix[1][1] << ' ' << other.matrix[2][1] << endl
               << other.matrix[0][2] << ' ' << other.matrix[1][2] << ' ' << other.matrix[2][2] << endl;
            return os;
        }

        int matrix[3][3];
};


int main()
{

  Matrix3 m1, m2, m3;
  bool option;
      m1.fill(10,21,2,43,2,1,44,4,9);
      m2.fill(1,82,3,3,3,44,34,34,32);
      m3 = m1 + m2;
      cout << m3 << "matrix1+matrix2"<< endl;
      m3 = m3*3;
      cout << m3 << "(matrix1+matrix2)*3"<< endl;
      m3=m3*m1;
      cout << m3<< "previous matrix *matrix1"<<endl;
      cout <<"do you want to fill a matrix with zeros or with random numbers?(0 for zeros/1 for other numbers.)"<<endl;
      cin >>option;
      m3.fill(option);
      cout << m3;

      return 0;

}
