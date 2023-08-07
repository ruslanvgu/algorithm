/***
 * O(n log n)
*/
#include <vector>
#include <iostream>

void quick_sort(std::vector<int> &vec, size_t left, size_t right)
{
    if (left < right)
    {
        size_t mid = vec[(right + left) / 2];
        size_t i = left, j = right;
        while (i <= j)
        {
            while (vec[i] < mid)
                i++;
            while (vec[j] > mid)
                j--;
            if (i <= j)
            {
                std::swap(vec[i++], vec[j--]);
            }
        }
        if (left < j)
            quick_sort(vec, left, j);
        if (i < right)
            quick_sort(vec, i, right);
    }
}

int main(int argc, char *argv[])
{
    using namespace std;
    vector<int> v{2, 4, 1, 4, 5, 13, 3, 5, 6, 1, 33};
    quick_sort(v, 0, v.size() - 1);
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}