#include <iostream>
#include "../include/matcal.h"

using namespace std;

MatCal::MatCal()
{
    // TODO : implement the constructor (if you need to)
    cout << "Hello MatCal!" << endl;
}

MatCal::~MatCal()
{
    // TODO : implement the destructor (if you need to)
    cout << "Bye MatCal!" << endl;
}

int MatCal::set(int idx, int rows, int cols, float *elements)
{
    // DEMO for array pointer (this part should be removed after the implementation)
    cout << "Elements : " << endl;
    for (int i_mat = 0; i_mat < rows; i_mat++)
    {
        for (int j_mat = 0; j_mat < cols; j_mat++)
        {
            cout << elements[i_mat * cols + j_mat] << " ";
        }
        cout << endl;
    } 
    // DEMO for array pointer (this part should be removed after the implementation)

    // TODO : implement the function
    return -1;
}

int MatCal::get(int idx, float *elements)
{
    // TODO : implement the function
    return -1;
}

int MatCal::add(int idx_in0, int idx_in1, int idx_out)
{
    // TODO : implement the function
    return -1;
}

int MatCal::mul(int idx_in0, int idx_in1, int idx_out)
{
    // TODO : implement the function
    return -1;
}

int MatCal::rref(int idx_in, int idx_out)
{
    // TODO : implement the function
    return -1;
}

void MatCal::display(int idx)
{
    cout << "Matrix " << idx << endl;
}
