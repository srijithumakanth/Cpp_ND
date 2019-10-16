#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int main()
{
    // Three ways of initializing vectors
    vector<int> v_1{1,2,3};  //Commonly used.

    //vector<int> v_2 = {3,4,5};
    auto v_2 = {3,4,5, 7,10,15,19};

    vector<int> v_3;
    v_3 = {7,8,9};

    // Creating 2D vectors
    //vector<vector<int>> v_4{{1,2}, {3,4}};
    auto v_5{{1,2}, {3,4}};

    for (auto i : v_2)
        cout << i << " ";
    cout << "\n";
    //cout << "Everything worked! \n";
    //cout << "A 2D vector was created. \n";
    //cout << "A 2D vector was created usin auto keyword. \n";
    return 0;
}