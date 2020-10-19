#include <iostream>
#include <chrono>
#include <string>

using namespace std;
void print(int *mas, int size, string direction)
{
    cout << "Massive "+direction+": ";
    for(int i=0; i < size; i++)
        cout << *(mas+i)<<" ";
    cout << endl;
}
void swap(int *last, int *next)
{
    int temp = *last;
    *last = *next;
    *next =temp;
}

void funcShakerSort(int *mas, int size)
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
    cout << endl << "Time: "<<chrono::duration_cast<chrono::milliseconds>(e-b).count() << endl;
}

int main(int argc, char *argv[])
{
    string size;
    while(1){
        try{
            srand(time(NULL));

            cout << "Input size massive: ";
            getline(std::cin, size);
            int s_mas = stoi(size);

            int *mas = new int[s_mas];

            for(int i = 0; i < s_mas; i++)
                *(mas+i) = rand()%50;

//            cout << "Input massive: ";
//            for(int i=0; i < s_mas; i++)
//                cout << *(mas+i)<<" ";
//            cout << endl;

            funcShakerSort(mas,s_mas);

//            cout << "Output massive: ";
//            for(int i=0; i < s_mas; i++)
//                cout << *(mas+i)<<" ";
//            cout << endl;


        }
        catch(std::invalid_argument &e)
        {
            cout << "Error input. Invalid argument. : " << e.what() << endl;
        }
        catch(std::out_of_range &e)
        {
            cout << "Error input. Out of range.  : " << e.what() << endl;
        }
    }
    return 0;
}
