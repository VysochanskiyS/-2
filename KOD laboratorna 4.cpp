#include <math.h>
class Circle 
  { 
    private:
double r;
const double pi = 3.1415926535897932384626433832795; 
public:
Circle(int **arr);
~Circle(){};
double lenght();
double diameter();
double square();
   }; 
Circle::Circle(int **arr) { r = sqrt(powl((arr[1][0] - arr[0][0]), 2) + powl((arr[1][1] - arr[0][1]), 2) + powl((arr[1][2] - arr[0][2]), 2)); }
double Circle::diameter() {
return (2 * r); }
double Circle::lenght() {
return (2 * pi * r); }
double Circle::square() {
return (pi * r * r); }
#include <iostream>
using namespace std;
int main() {
setlocale(LC_ALL, "Ukrainian");
int **arr = new int *[2];
for (int i = 0; i < 2; i++)
{
arr[i] = new int[3];
if (i == 0)
cout << "Введiть координати x, y, z центру кола:" << endl;
else if (i == 1)
cout << "Введiть координати x, y, z точки на колi:"; cin>> arr[i][0] >> arr[i][1] >> arr[i][2];
}
Circle circle(arr);
cout << "Довжина кола: " << circle.lenght() << endl;
cout << "Площа круга: " << circle.square() << endl;
cout << "Дiаметр: " << circle.diameter() << endl;
for (int i = 0; i < 2; i++)
delete[] arr[i];
delete[] arr;
}


