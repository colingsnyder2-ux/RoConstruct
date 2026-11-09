// from server: 73% by colin
struct S {
    int f(int*);
};

int S::f(int* p)
{
    int* edx;
    if (*(int*)((char*)this + 0x10) != 0)
        edx = 0;
    else
        edx = *(int**)((char*)this + 8);

    if (edx != 0) {
        double d = *(double*)((char*)p + 8);
        while (1) {
            double e = *(double*)edx;
            if (e > d)
                (*p)++;
            edx = (int*)((char*)edx + 8);
            if (edx == *(int**)((char*)this + 4))
                edx = *(int**)this;
            if (edx == *(int**)((char*)this + 0xc))
                break;
            if (edx == 0)
                break;
        }
    }
    return 0;
}
