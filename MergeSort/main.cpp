//Сортировка слиянием во многом похожа на метод быстрой сортировки.  Производительность сортировки слиянием лежит между производительностью пирамидальной и быстрой сортировки.
//Но в отличие от пирамидальной и быстрой сортировок, метод сортировки слиянием ведет себя стабильно, поскольку он не зависит от перестановок элементов в массиве.
//Еще одним достоинством сортировки слиянием является то, что он удобен для структур с последовательным доступом к элементам, таким как файлы на внешнем устройстве или связные списки.
//Этот метод, прежде всего, используется для внешней сортировки.
//Недостатки метода заключаются в том, что он требует дополнительной памяти по объему равной объему сортируемого файла. Поэтому для больших файлов проблематично организовать
//сортировку слиянием в оперативной памяти.
//В случаях, когда гарантированное время сортировки важно и размещение в оперативной памяти, возможно, следует предпочесть метод сортировки слиянием.

#include <iostream>
#include <string>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>
using namespace std;

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

void Merge(int *A, int first, int last)
{
    int middle, start, final, j;
    int *mas=new int[100];
    middle=(first+last)/2; //вычисление среднего элемента
    start=first; //начало левой части
    final=middle+1; //начало правой части
    for(j=first; j<=last; j++) //выполнять от начала до конца
    if ((start<=middle) && ((final>last) || (A[start]<A[final])))
    {
        mas[j]=A[start];
        start++;
    }
    else
    {
        mas[j]=A[final];
        final++;
    }
    //возвращение результата в список
        for (j=first; j<=last; j++) A[j]=mas[j];
        delete[]mas;
};
    //рекурсивная процедура сортировки
void MergeSort(int *A, int first, int last)
{
    {
        if (first<last)
        {
            MergeSort(A, first, (first+last)/2); //сортировка левой части
            MergeSort(A, (first+last)/2+1, last); //сортировка правой части
            Merge(A, first, last); //слияние двух частей
        }
    }
};

int main(int argc, char *argv[])
{

    string strSize;
    srand(time(NULL));
    try{
        cout << "Input size: ";
        getline(std::cin,strSize);
        int s = stoi(strSize);
        int mass[s];
        fillingMassive(mass,s);
        printMassive(mass,s);
        MergeSort(mass,0,s-1);
        printMassive(mass,s);
    }
    catch(std::invalid_argument &e)
    {
        cout << "Error input: " << e.what() << endl;
    }
    catch(std::out_of_range &e)
    {
        cout << "Error input: " << e.what() << endl;
    }

    return 0;
}
