#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <thread>


std::vector<int>::iterator binary_search(std::vector<int> &vec, int x)
{
    if(x >vec.back() || x <vec.front())
        return vec.end();

    int left = 0, right = vec.size() - 1;
    while(left <= right)
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

int blockBinarySearch(const std::vector<int>& arr, int key, int blockSize) {
    int n = arr.size();
    int numBlocks = n / blockSize;

    // Создаем массив B из первых элементов блоков
    std::vector<int> blocks;
    for (int i = 0; i < numBlocks; i++) {
        blocks.push_back(arr[i * blockSize]);
    }

    // Ищем ближайший блок в массиве B
    int low = 0, high = numBlocks - 1;
    int blockIndex = -1;
    while (low <= high) {
        int mid = low + (high - low) * (key - blocks[low]) / (blocks[high] - blocks[low]);
        if (blocks[mid] == key) {
            blockIndex = mid;
            break;
        } else if (blocks[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Если блок был найден, выполняем двоичный поиск в соответствующем блочном массиве
    if (blockIndex != -1) {
        int start = blockIndex * blockSize;
        int end = std::min(start + blockSize - 1, n - 1);

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == key) {
                return mid;
            } else if (arr[mid] < key) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1; // Элемент не найден
}

void generator(std::vector<int>& vec, int n)
{
    vec.reserve(n);
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, 10000);
    
    for (int i = 0; i < n; ++i) {
        int random_number = distribution(generator);
        vec.push_back(random_number);
    }
}

template<class TypeTime>
class OTimer
{
    using tp = std::chrono::time_point<std::chrono::steady_clock>;
    tp start, stop;

public:
    void start_()
    {
        start = std::chrono::steady_clock::now();
    }

    void stop_()
    {
        using namespace std::chrono;
        stop = steady_clock::now();
        double nanosec = duration_cast<TypeTime>(stop - start).count();
        std::cout <<"Execution time sec: "<< nanosec << std::endl;
    }
};


int main(int argc, char* argv[])
{
    using namespace std;
    using namespace chrono;
    OTimer<std::chrono::nanoseconds> timer;

    cout << "1. Filling vector "<< endl;
    int n = pow(2,25);
    vector<int> v;
    generator(v,n);
    
    cout << "2. Sorting " << endl;
    sort(v.begin(), v.end());    

    cout << "3. Search" <<endl;
    timer.start_();
    auto it = binary_search(v,1);
    timer.stop_();

    cout << "Resault: ";
    if(it != v.end())
        cout << *it << endl;
    else
        cout << "Not found" <<endl;

    cout << "5. OSearch " <<endl;
    int blockSize = sqrt(n);
    timer.start_();
    int res = blockBinarySearch(v, 231, blockSize);
    timer.stop_();
    cout << "Resault: ";
    if(res != -1)
        cout << res << endl;
    else 
        cout << "Not found" <<endl;

}