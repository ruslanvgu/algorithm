///Бинарный поиск — очень быстрый алгоритм с не сложной реализацией,
///который находит элемент с определенным значением в уже отсортированном массиве.
///Очень важно помнить! Алгоритм будет работать правильно, только с отсортированным массивом.
///А если по случайности вы забыли отсортировать массив перед его использованием, то в
///большинстве случаев тот ответ, который подсчитал алгоритм, будет неверным.
///O(log n)

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <parallel/algorithm>

using namespace  std;

bool BinarySearch(int *mass, int size, int num){

    int pBeg = 0;
    int pEnd = size;

    int mid =0;
    while(pBeg <= pEnd)
    {
        mid =      (pEnd + pBeg)
              / //----------------------
                        2;
        if(num < mass[mid]) pEnd = mid-1;
        else if(num > mass[mid]) pBeg = mid+1;
        else if(num == mass[mid]) return true;

    }
    return  false;
}

int main(int argc, char *argv[])
{
    string size, s_num;
    int *mass = nullptr;


    while(1){
        try{

            cout << "BinarySearch" << endl;
            cout << "Input size massive: ";

            getline(std::cin, size);
            int s_mass = stoi(size);

            if(s_mass > 10000) throw std::out_of_range("More 10000");

            mass = new int[s_mass];
             srand(time(NULL)); //инициализация генератора случайных чисел rand
            for(int i = 0; i < s_mass; i++){
                mass[i] = rand() % 50;
            }

            sort(mass,mass+s_mass);

            for(int i = 0; i < s_mass; i++){
               cout << mass[i] << " ";
            }

            cout << endl << "Input number: ";
            getline(std::cin, s_num);
            int num = stoi(s_num);
            int timeDuration=0;

            bool flag = false;

            chrono::time_point<chrono::steady_clock> b = chrono::steady_clock::now();

            flag = BinarySearch(mass, s_mass, num);

            chrono::time_point<chrono::steady_clock> e = chrono::steady_clock::now();
            timeDuration = chrono::duration_cast<chrono::milliseconds>(e-b).count();

            /*flag = searchNumber(mass, s_mass, num, timeDuration);*/
            (flag == true) ? cout << "Find success" <<endl : cout << "Find unsuccess" <<endl;
            cout << "Time: " << timeDuration <<" milisec"<<endl;

            delete[] mass;
        }
        catch(std::invalid_argument &e)
        {
            cout << "Error input: " << e.what() << endl;
            if(mass) delete[] mass;
            return 1;
        }
        catch(std::out_of_range &e)
        {
            cout << "Error input: " << e.what() << endl;
            if(mass) delete[] mass;
            return 1;
        }
    }
    return 0;
}
