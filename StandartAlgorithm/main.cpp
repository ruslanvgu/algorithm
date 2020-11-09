

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
int main(int argc, char *argv[])
{
    //find
    std::vector<int> vec{1,3,1,4,5};
    auto rez= std::find(vec.begin(),vec.end(),4);
    if (rez != std::end(vec)) {
        std::cout << "v contains " <<std::endl;
    } else {
        std::cout << "v does not contain " << std::endl;
    }

    std::vector<int> vec1{1,3,1,4,5,11,4,14};
    std::vector<int>::iterator rez1;
    rez1= std::find_if(vec1.begin(),vec1.end(),[](int i){
        return i >10;});
    while(rez1 != vec1.end()){
        std::cout << *rez1 <<" "<<std::endl;
        rez1= std::find_if(std::next(rez1),vec1.end(),[](int i){
            return i >10;});
    }

    std::string str1 = "Text with some   spaces";
       auto i = std::remove(str1.begin(), str1.end(), ' ');

        std::cout << *i << '\n';



    return 0;
}
