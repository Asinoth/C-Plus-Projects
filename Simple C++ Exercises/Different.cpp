//This programme find the % difference between two text files.

#include "std_lib_facilities.h" //headerfile
#include <fstream>

//function declarations
int minimum(int a,int b,int c);

string delete_the_new_line(string s);

double levdis(const string s1,const string s2);

void percentage(string s1,string s2,double dif);


/*MAIN*/
int main()
{
  ifstream file1("Read_a.txt");//open the files to read
  ifstream file2("Read_b.txt");


  string line1((istreambuf_iterator<char>(file1)), (istreambuf_iterator<char>()));//put the file1 in a string
  string line2((istreambuf_iterator<char>(file2)), (istreambuf_iterator<char>()));//put the file 2 in a string

  line1=delete_the_new_line(line1);//delete the \n
  line2=delete_the_new_line(line2);//delete the \n

 percentage(line1,line2,levdis(line1,line2));//prints ans finds the % difference

return 0;

}


/*FUNCTIONS*/

void percentage(string s1,string s2,double dif) //prints the difference%
{
  cout<<"The file A and file B are "<<setprecision(3)<<dif<<"% "<< "different.\n";
}




double levdis(const string s1,const string s2)//finds the difference
{
  int n=s1.length();
  int m=s2.length();
  if(n==0) return 0;
  if (m==0) return 0;
  unsigned int matrix[n+1][m+1];
  int diff,i,j,cost;


  for(i=0;i<=n;i++)
  {
    for(j=0;j<=m;j++)
    {
      matrix[i][j]=0; //first we put all the cels as 0
    }
  }


  for (i=1;i<=n;i++)
  {
    matrix[i][0]=i; //initialize the first row to 0...n
  }


  for (j=1;j<=m;j++)
  {
    matrix[0][j]=j; // initialize the first column to 0...m
  }


  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      if(s1[i-1]==s2[j-1])//examine each character
      {
        cost=0; //if same the cost is 0
        matrix[i][j]=matrix[i-1][j-1];
      }else{
        cost=1; //if they are not the same the cost is 1

      matrix[i][j]=minimum((matrix[i-1][j]+1),(matrix[i][j-1]+1),(matrix[i-1][j-1]+cost));
      }
    }
  }
int max_length=max(s1.length()-1,s2.length()-1); //find the bigger string
double percent=matrix[n][m]*100/double(max_length);//find the percent of difference
return percent;

}



string delete_the_new_line(string s)//deletes the \n
{
  string::size_type pos=0;
  while((pos=s.find("\r\n",pos))!=string::npos)
  {
    s.erase(pos,2);
  }

return s;
}



int minimum(int a,int b,int c)//finds the smaller
{
  int result = min(min(a,b),c); //calls twice the function min
  return result;
}
