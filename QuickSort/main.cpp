
#include <string>
#include <iostream>
#include <chrono>

using namespace std;


void printMass(int *mass, int size)
{
    for (int i = 0; i < size; ++i) {
        cout << mass[i] << " ";
    }
    cout << endl;
}

void quickSort(int *mass, int first, int last)
{
    if(first < last){
        int left = first;
        int right = last;
        int mid = mass[(left+right)/2];
        do{
            while(mass[left] < mid) left++;
            while(mass[right] > mid) right--;
            if(left <= right){
                int tmp = mass[left];
                mass[left] = mass[right];
                mass[right] = tmp;
                left++; right--;
            }
          //  printMass(mass, last);
        } while(left <= right);
        quickSort(mass, first, right);
        quickSort(mass, left,last);
    }
}

int main(int argc, char *argv[])
{
    string size="", s_num="";
    int *mass=nullptr;
    srand(time(NULL)); //инициализация генератора случайных чисел rand

    while(1){
        try{
            cout << "QuickSort" << endl;
            cout << "Input size massive: ";
            getline(std::cin, size);
            int s_mass = stoi(size);
            mass = new int[s_mass];
            for(int i = 0; i < s_mass; i++){
                mass[i] = rand() % 50;
            }

            printMass(mass, s_mass);
            int timeDuration=0;
            chrono::time_point<chrono::steady_clock> b = chrono::steady_clock::now();
            quickSort(mass,0,s_mass-1);
            chrono::time_point<chrono::steady_clock> e = chrono::steady_clock::now();
            timeDuration = chrono::duration_cast<chrono::milliseconds>(e-b).count();
            printMass(mass,s_mass);
            cout << "Time QuickSort: " << timeDuration <<" milisec"<<endl;
        }
        catch(std::invalid_argument &e)
        {
            cout << "Error input: " << e.what() << endl;
        }
        catch(std::out_of_range &e)
        {
            cout << "Error input: " << e.what() << endl;
        }
        delete mass;
    }
    return 0;
}
