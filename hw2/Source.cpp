#include <iostream>
#include <Windows.h>
#include <iomanip>

#include <time.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;


class Student {
public:

    Student(string fn , string ln , int age_ , double avg = 0) { // конструктор с параметрами по умолчанию
        FN = fn;
        LN = ln;
        age = age_;
        average = 0;
    }

    Student() {

    }

    void SearchAVG() {
        double sum = 0;
        for (int i = 0; i < 3; i++)
        {
            arr_score[i] = rand() % 12 + 1;
        }
        for (int i = 0; i < 3; i++) {
            sum += arr_score[i];
        }
        average = (double)sum / 3.0;
    }



    void Print() {
        cout << FN << " " << LN << " age = " << age << "/ ";
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << " score = " << arr_score[i] << "/ ";
        }
        cout << " average = " << average << endl;
    }

     double getAVG() {
         double avg = 0;
         for (int i = 0; i < 3; i++)
         {
             avg += arr_score[i];
         }
         avg /= 3;
         return avg;
     }

       void setScore() {
           for (int i = 0; i < 3; i++)
           {
               arr_score[i] = rand() % 12 + 1;
           }
       }

        void setAVG() {
            average = getAVG();
        }

        void printArr(Student arr[]) {
            for (int i = 0; i < 10; i++) {
                arr[i].setScore();
                arr[i].setAVG();
                arr[i].getAVG();
                arr[i].Print();
            }
        }


        void sortByAge(Student arr[], int length) {
            cout << "\n\nSort by age:\n\n";
            for (int i = length - 1; i > 0; i--) {
                for (int j = 0; j  < i; j++) {
                    if (arr[j].age > arr[j + 1].age) {
                        swap(arr[j].age, arr[j + 1].age);
                        swap(arr[j].FN, arr[j + 1].FN);
                        swap(arr[j].LN, arr[j + 1].LN);
                        swap(arr[j].average, arr[j + 1].average);
                    }
                }
               
            }
          /*  for(int i = 0; i < length; i++)
                cout << arr[i].age << endl;*/
        }

        void sortBySurname(Student arr[], int length) {
            cout << "\n\nSort by last name:\n\n";
            for (int i = length - 1; i > 0; i--) {
                for (int j = 0; j < i; j++) {
                    if (arr[j].LN > arr[j + 1].LN) {
                        swap(arr[j].age, arr[j + 1].age);
                        swap(arr[j].FN, arr[j + 1].FN);
                        swap(arr[j].LN, arr[j + 1].LN);
                        swap(arr[j].average, arr[j + 1].average);
                    }
                }

            }
        }





private:
    string FN;
    string LN;
    int age;
    int arr_score[3] = {};
    double average;


};



void main()
{
    srand(time(NULL));

    Student st1;

    Student arr[10] = {
        Student("Maria", "Acceva", 56), 
        Student("Vanya", "Petrov", 33),
        Student("Peter", "Villy", 46),
        Student("Zhenya", "Berdon", 18),
        Student("Alex", "Krasov", 19),
        Student("Anya", "Midu", 28),
        Student("Olga", "Budkov", 35),
        Student("Oleg", "Gengi", 44),
        Student("Kith", "Rasst", 19),
        Student("Kitty", "Meow", 22),
    };

    st1.printArr(arr);

    st1.sortByAge(arr, 10);
    
    st1.printArr(arr);

    st1.sortBySurname(arr, 10);

    st1.printArr(arr);
    

    

}