// from server: 76% by tester
struct S {
    int f(int* p);
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
};

int S::f(int* p)
{
    int* edx;
    if (field10 != 0)
        edx = 0;
    else
        edx = (int*)field8;

    if (edx != 0) {
        do {
            double a = *(double*)((char*)p + 8);
            double b = *(double*)edx;
            if (b > a)
                (*p)++;
            edx = (int*)((char*)edx + 8);
            if (edx == (int*)field4)
                edx = (int*)field0;
            if (edx == (int*)fieldC)
                break;
        } while (edx != 0);
    }
    return 0;
}
