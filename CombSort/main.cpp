///s/=1.247f

#include <string>
#include <iostream>
using namespace std;
template <class T>
void swap(T *last, T *next)
{
    int temp = *last;
    *last = *next;
    *next =temp;
}

template <class T>
void fillingMassive(T* mass, int size)
{
    for(int i=0; i < size; i++)
        *(mass+i) = rand()%50;
}
template <class T>
void printMassive(T* mass, int size)
{
    cout << "Output massive: ";
    for(int i=0; i < size;  i++)
        cout <<*(mass+i)<<" ";
    cout << endl;
}

void funcCombSort(int *mass, int size)
{
    int s=size;
    bool flag=true;
    while(flag)
    {
        s/=1.247f;
        if(s < 1) flag =false;
        if(s < 1) s=1;
        for(int i=0; i+s < size; i++  )
           if( *(mass+i) > *(mass +i+s))
               swap(mass+i,mass+i+s);

    }
}

int main(int argc, char *argv[])
{
    string sSize;
    int *mass;
    while(1){
        try{
            srand(time(NULL));
            cout << "CombSort" << endl;
            cout << "Input size massive: ";
            getline(std::cin,sSize);
            int size = stoi(sSize);
            mass = new int[size];
            fillingMassive(mass,size);
            funcCombSort(mass,size);
            printMassive(mass,size);

        }
        catch(std::invalid_argument &e)
        {
            cout << "Error input: " << e.what() << endl;
        }
        catch(std::out_of_range &e)
        {
            cout << "Error input: " << e.what() << endl;
        }
    }

    return 0;
}
