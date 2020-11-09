///сложность от O(n)-O((n)в кв.)
///в пузырьковой сортировке тяжелые элементы быстро тонут , а легкие долго всплывают

#include <string>
#include <iostream>
#include <chrono>
using namespace std;

void sort(int * mass, int size)
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
    cout << endl << "Time: "<<chrono::duration_cast<chrono::milliseconds>(e-b).count() << endl;

}

int main(int argc, char *argv[])
{
    string s_size;
    srand(time(NULL));
    while(1){
        cout << endl;
        cout << "BubbleSort" << endl;
        cout << "Input massive size: ";
        try{
            getline(cin, s_size);
            int size = stoi(s_size);

            int mass[size];
            for(int i=0; i< size; i++)
                mass[i] = rand() % 50;

            cout << "Изначальный массив: " ;
            for(auto &i : mass)
                cout << i <<" ";

            sort(mass, size);

           cout << "Отсортированный массив: " ;
            for(auto &i : mass)
                cout << i <<" ";
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
    system("pause");
    return 0;
}
