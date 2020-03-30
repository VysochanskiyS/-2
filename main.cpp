#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    while (true)
    {
        setlocale(LC_ALL, "ukr");
        cout << "Показати данi - натиснiть 1" << endl;
        cout << "Записати данi - натиснiть 2" << endl;
        cout << "Вихiд - натиснiть 3" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            
            
           
            int numeric;
            float root;
            ifstream infile;
            infile.open("File.txt");
            if (!infile)
            {
                cout << "Не можна вiдкрити файл" << endl;
                return -1;
            }
            cout << setw(9) << "Число" << setw(19) << "Квадратний корiнь" << endl;
            while (!infile.eof())
            {
                infile >> numeric;
                infile >> root;
               
                if (!infile.eof())
                {
                    cout.width(9);
                    cout << numeric;
                    cout.width(9);
                    cout << root;
                   
                    cout << endl;
                }
            }
            infile.close();
        }
        if (choice == 2)
        {

           
            float numeric;
            float n=1;
            float root;
            cout << "Число: ";
            cin >> numeric;
            root = sqrt(numeric);


            fstream outfile("File.txt", ios::app);
            if (!outfile)
            {
                cout << "Не можна вiдкрити файл" << endl;
                return -1;
            }
            outfile.setf(ios::left);
            outfile.width(9);
            outfile << numeric << ' ';
            outfile.width(18);  
            outfile << root << endl;
            while((numeric/=10) > 0)n++;
            outfile.width(27);
            outfile<<n<<endl;
            outfile.close();
        }

        if (choice == 3)
        {
            break;
        }
    }
    system("pause");
}


