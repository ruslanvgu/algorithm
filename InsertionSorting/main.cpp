
#include "/home/sintez/projects/general/GeneralFunction.h"
using namespace std;
void insertionSort(int *mas, size_t size)
{

    int tmp;
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
}

int main(int argc, char *argv[])
{
    string sSize;
    int *mass;
    while(1){
        try{

            cout << "Input size massive: ";
            getline(std::cin,sSize);
            int size = stoi(sSize);
            mass = new int[size];
            fillingMassive(mass,size);
            insertionSort(mass,size);
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
