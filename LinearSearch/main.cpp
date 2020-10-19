
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
using namespace  std;

int searchMaxInMassive(int *mass, int size, int &timeDuration){

    int maxV = mass[0];
    chrono::time_point<chrono::steady_clock> b = chrono::steady_clock::now();
    for(int i =0; i < size; i++){
        if(maxV < mass[i])
            maxV = mass[i];
    }
    chrono::time_point<chrono::steady_clock> e = chrono::steady_clock::now();
    timeDuration = chrono::duration_cast<chrono::milliseconds>(e-b).count();

    return maxV;
}

bool LinearSearch(int *mass, int size, int num, int &timeDuration){

    bool flag = false;
    chrono::time_point<chrono::steady_clock> b = chrono::steady_clock::now();
    for(int i =0; i < size; i++){
        if(num == mass[i]){
            flag = true;
            break;
        }
    }
    chrono::time_point<chrono::steady_clock> e = chrono::steady_clock::now();
    timeDuration = chrono::duration_cast<chrono::milliseconds>(e-b).count();
    return flag;
}



int main(int argc, char *argv[])
{
    int a,b,c;


    bool flag =true;
    string size;
    int *mass;
    srand(time(NULL)); //инициализация генератора случайных чисел rand

    while(flag == true){
        cout << "Input size massive: ";
        try{
            getline(std::cin, size);
            int s_mass = stoi(size);
            //int mass[s_mass];
            mass = new int[s_mass];
            for(int i = 0; i < s_mass; i++){
                mass[i] = rand() % 50;
            }

            int maxValue=0;
            int timeDuration=0;
            //int maxValue = searchInMassive(mass, s_mass,timeDuration);

            thread th([mass, &s_mass,&timeDuration, &maxValue ]() {
                maxValue = searchMaxInMassive(mass,s_mass,timeDuration);
                }
            );

            th.join();
            cout << "Max number: " <<  maxValue << endl;
            cout << "Time: " << timeDuration <<" milisec"<<endl;

            bool flag = false;
            int num =16;
            thread th1([mass, &s_mass,&timeDuration,&num, &flag](){
                flag = LinearSearch(mass, s_mass, num, timeDuration);
            });
            th1.join();
            (flag == true) ? cout << "Find success" <<endl : cout << "Find unsuccess" <<endl;
            cout << "Time: " << timeDuration <<" milisec"<<endl;

        }
        catch(std::invalid_argument &e)
        {
            cout << "Error input. Invalid argument. : " << e.what() << endl;
        }
        catch(std::out_of_range &e)
        {
            cout << "Error input. Out of range.  : " << e.what() << endl;
        }
        delete mass;

    }
    return 0;
}

