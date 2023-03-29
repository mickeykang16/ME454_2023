#include "include/matcal.h"

int main()
{
    MatCal mat_cal;
    
    float elements[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    mat_cal.set(0, 2, 3, elements);
    mat_cal.display(0);
    
    return 0;
}