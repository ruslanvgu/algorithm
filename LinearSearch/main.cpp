
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

void print_massive(int *mass, int size){
    for (int i = 0; i < size; ++i) {
        std::cout << mass[i] << " ";
    }
    std::cout << std::endl;
}

bool LinearSearch(int *mass, int size, int num, int &timeDuration){
    chrono::time_point<chrono::steady_clock> b = chrono::steady_clock::now();
    for(int i =0; i < size; i++){
        if(num == mass[i]){
            return true;
        }
    }
    chrono::time_point<chrono::steady_clock> e = chrono::steady_clock::now();
    timeDuration = chrono::duration_cast<chrono::milliseconds>(e-b).count();
    return false;
}



int main(int argc, char *argv[])
{
    int a,b,c;

    bool flag =true;
    string valueStr;
    int *mass=nullptr;
    srand(time(NULL)); //инициализация генератора случайных чисел rand

    while(flag == true){
        try{
            cout << "Linear search" << endl;
            cout << "Input size massive: ";
            getline(std::cin, valueStr);
            int s_mass = stoi(valueStr);

            if(s_mass > 10000) throw std::out_of_range("More 10000");

            mass = new int[s_mass];
            for(int i = 0; i < s_mass; i++){
                mass[i] = rand() % 50;
            }
            //print_massive(mass,s_mass);

            int timeDuration=0;
            bool flag = false;
            cout << "Input value for search: ";
            getline(std::cin, valueStr);
            int value = stoi(valueStr);

             flag = LinearSearch(mass, s_mass, value, timeDuration);

            (flag == true) ? cout << "Find success" <<endl : cout << "Find unsuccess" <<endl;
            cout << "Time: " << timeDuration <<" milisec"<<endl;
            delete[] mass;


        }
        catch(std::invalid_argument &e)
        {
            cout << "Error input. Invalid argument. : " << e.what() << endl;
            if(mass) delete[] mass;
            return 1;
        }
        catch(std::out_of_range &e)
        {
            cout << "Error input. Out of range.  : " << e.what() << endl;
            if(mass) delete[] mass;
            return 1;
        }

    }

    return 0;
}

