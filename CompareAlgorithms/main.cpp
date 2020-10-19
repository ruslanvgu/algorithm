#include <string>
#include <iostream>
#include <chrono>

using namespace std;

template <class T>
void swap(T *last, T *next)
{
    int temp = *last;
    *last = *next;
    *next =temp;
}

void fillMass(int *mass, int size)
{
    for (int i = 0; i < size; ++i) {
       mass[i] = rand() % 50;
    }
}

void BubbleSort(int * mass, int size)
{
    int n = size,k=0;
    int flag = true;
    chrono::time_point<chrono::steady_clock> b = chrono::steady_clock::now();
    while(flag){
        flag = false;

        for(int i=0; i < n; i++)
            if(mass[i] > mass[i+1]){
                int temp = mass[i+1];
                mass[i+1] = mass[i];
                mass[i] = temp;
                flag = true;
                k=i;
            }
        n=k;
    }

    chrono::time_point<chrono::steady_clock> e = chrono::steady_clock::now();
    cout << endl << "BubbleSort time: "<<chrono::duration_cast<chrono::milliseconds>(e-b).count()<<" milisec" << endl;
}


void CombSort(int *mass, int size)
{
    int s=size;
    bool flag=true;
    chrono::time_point<chrono::steady_clock> b = chrono::steady_clock::now();
    while(flag)
    {
        s/=1.247f;
        if(s < 1) flag =false;
        if(s < 1) s=1;
        for(int i=0; i+s < size; i++  )
           if( *(mass+i) > *(mass +i+s))
               swap(mass+i,mass+i+s);
    }
    chrono::time_point<chrono::steady_clock> e = chrono::steady_clock::now();
    cout << endl << "ComboSort time: "<<chrono::duration_cast<chrono::milliseconds>(e-b).count()<<" milisec" << endl;
}

void InsertionSort(int *mas, size_t size)
{

    int tmp;
    chrono::time_point<chrono::steady_clock> b = chrono::steady_clock::now();
    for(int j=0; j < size; j++)
    {
        int min = j;

        for(int i=j; i < size; i++)
            if(mas[i] < mas[min]) min = i;
        if(j != min){
            tmp = mas[j];
            mas[j]=mas[min];
            mas[min] = tmp;
        }
    }
    chrono::time_point<chrono::steady_clock> e = chrono::steady_clock::now();
    cout << endl << "InsertionSort time: "<<chrono::duration_cast<chrono::milliseconds>(e-b).count()<<" milisec" << endl;
}

void ShakerSort(int *mas, int size)
{
    int left=0;
    int right=size;
    chrono::time_point<chrono::steady_clock> b = chrono::steady_clock::now();
    while(left <= right)
    {
        for(int i=left; i < right; i++)
            if(*(mas+i) > *(mas+i+1)) swap(mas+i,mas+i+1);
        right--;

        for(int i=right; i > left; i--)
            if(*(mas+i) < *(mas+i-1)) swap(mas+i,mas+i-1);
        left++;

    }
    chrono::time_point<chrono::steady_clock> e = chrono::steady_clock::now();
    cout << endl << "ShakerSort time: "<<chrono::duration_cast<chrono::milliseconds>(e-b).count()<<" milisec" << endl;
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
        } while(left <= right);
        quickSort(mass, first, right);
        quickSort(mass, left,last);
    }

}
void QuickSort(int *mass, int first, int last)
{
    chrono::time_point<chrono::steady_clock> b = chrono::steady_clock::now();
    quickSort(mass,  first, last);
    chrono::time_point<chrono::steady_clock> e = chrono::steady_clock::now();
    cout << endl << "QuickSort time: "<<chrono::duration_cast<chrono::milliseconds>(e-b).count()<<" milisec" << endl;
}

int main(int argc, char *argv[])
{


    string size, s_num;
    int *mass;
    srand(time(NULL)); //инициализация генератора случайных чисел rand

    while(1){
        try{
            cout << "Input size massive: ";
            getline(cin, size);
            int s_mass = stoi(size);
            mass = new int[s_mass];
            fillMass(mass,s_mass);
            BubbleSort(mass,s_mass);

            fillMass(mass,s_mass);
            CombSort(mass,s_mass);

            fillMass(mass,s_mass);
            InsertionSort(mass, s_mass);

            fillMass(mass,s_mass);
            ShakerSort(mass, s_mass);

            fillMass(mass,s_mass);
            QuickSort(mass,0,s_mass);

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
