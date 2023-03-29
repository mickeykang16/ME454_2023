#ifndef MATCAL_H_
#define MATCAL_H_

class MatCal
{
    public:
        MatCal();
        ~MatCal();
        int set(int idx, int rows, int cols, float *elements);
        int get(int idx, float *elements);
        int add(int idx_in0, int idx_in1, int idx_out);
        int mul(int idx_in0, int idx_in1, int idx_out);
        int rref(int idx_in, int idx_out);
        void display(int idx);

    private:
        // TODO : add any variable such as matrix storage
};

#endif