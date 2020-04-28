#include <math.h>
#include <iostream>
#include <string>
class Triangle
  { 
      private:
      double max;
      double r;
      double p;
      double pp;
      private:
      double a;
      double b;
      double c;
public:
Triangle(int **arr);
~Triangle(){};
double right();
double type();
double perimetr();
double square();
   }; 
Triangle::Triangle(int **arr) { 
    a = sqrt(powl((arr[1][0] - arr[0][0]), 2) + powl((arr[1][1] - arr[0][1]), 2) + powl((arr[1][2] - arr[0][2]), 2));
    b = sqrt(powl((arr[2][0] - arr[1][0]), 2) + powl((arr[2][1] - arr[1][1]), 2) + powl((arr[2][2] - arr[1][2]), 2));
    c = sqrt(powl((arr[2][0] - arr[0][0]), 2) + powl((arr[2][1] - arr[0][1]), 2) + powl((arr[2][2] - arr[0][2]), 2));
    p = a+b+c;
    pp=((a+b+c)/2);
}
double Triangle::perimetr() 
{
return (p); 
}
double Triangle::right() {
max=a;
if ( max < b)
b = max;
else if (max < c)
c = max;
return ( max );
}
double::Triangle::type(){
  
    if(max==sqrt(pow(a,2)+pow(b,2))||max==sqrt(  pow(b,2)+pow(c,2))||max==sqrt(pow(a,2)+pow(c,2)))
return (1);
else
    return(0);
}
double Triangle::square() {
return (sqrt(pp*(pp-a)*(pp-b)*(pp-c))); }

using namespace std;
int main() {
setlocale(LC_ALL, "Ukrainian");
int **arr = new int *[3];
for (int i = 0; i < 3; i++)
{
arr[i] = new int[3];
 if (i == 0)
cout << "Введiть координати 1 сторони: "; 
 else if (i == 1)
cout << "Введiть координати 2 сторони: ";
 else if (i == 2)
cout << "Введiть координати 3 сторони: "; cin>> arr[i][0] >> arr[i][1] >> arr[i][2];


}
Triangle triangle(arr);
cout << "Прямокутний: " << triangle.type() << endl;
cout << "Площа трикутника: " << triangle.square() << endl;
cout << "Периметр: " << triangle.perimetr() << endl;
for (int i = 0; i < 2; i++)
delete[] arr[i];
delete[] arr;
}


