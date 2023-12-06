//This programme finds the distance between two points of n-dimentions.


#include "std_lib_facilities.h" //header file
/*functions*/
double Euclidean_Distance(vector<int>& v1,vector<int>& v2);

/*main*/
int main(int argc, char **argv)
{
//declarations
  double Dis;

  vector<int> point1,point2; //make my points
  point1.push_back(1);
  point1.push_back(3);
  point1.push_back(0);
  point1.push_back(1);
  point1.push_back(0);

  point2.push_back(4);
  point2.push_back(6);
  point2.push_back(3);
  point2.push_back(0);
  point2.push_back(1);

  if(point1.size()!=point2.size())
  {
    cout << "The dimentios are not equal" << '\n';
    return -1;
  }

  Dis=Euclidean_Distance(point1,point2);

  cout << "The Euclidean Distance for the given points p,g is d(p,g)=" << Dis<< endl;
  return 0;
}

 double Euclidean_Distance(vector<int>& v1,vector<int>& v2)//finds the distance
{                                       //between two points with the Euclidean distance

  int sv1=v1.size();
  int sv2=v2.size();
  int big,i,sum=0;

  if(sv1>=sv2)
  {
    big=sv1;
    for( i=0;i<big;i++)
    {
      v2.push_back(0);
    }

  }else
  {
    big=sv2;
    for(i=0;i<big;i++)
    {
      v1.push_back(0);
    }
  }
  //in a general solution if the two points are not the same dimention
  //in the one point which has less dimentions we put the dimentions it does not have
  // as zeros so the (x2-x1)(x2-x1)=x2*x2 or x1*x1.


  for(i=0;i<big;i++)
  {
    sum=sum+((v2[i]-v1[i])*(v2[i]-v1[i]));
  }
//the type is the root of (x2-x1)(x2-x1) for all the dimentions
return sqrt(sum);

}
