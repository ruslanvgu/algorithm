/**
 * O(log n)
*/
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int>::iterator binary_search(std::vector<int> &vec, int x)
{
    if(vec.front() >  vec.back())
        return vec.end();
    if(x >vec.back() || x <vec.front())
        return vec.end();

    int left = 0, right = vec.size() - 1;
    while(left < right)
    {
        int mid = (left + right)/2;
        if(vec[mid] == x)
            return vec.begin() + mid;
        else if(x > vec[mid]){
            left = mid + 1;
        } else {
            right = mid - 1;    
        }
    }
    return vec.end();
}

int main(int argc, char* argv[])
{
    using namespace std;
    vector<int> v{2, 4, 1, 4, 5, 13, 3, 5, 6, 1, 33};
    sort(v.begin(), v.end());
    for(auto i : v){
        cout << i ;
        if(v.back() != i)
            cout << ",";
    }
    cout << endl;
    auto it = binary_search(v,13);
    if(it != v.end())
        cout << *it << endl;
    else
        cout << "Not found" <<endl;
}