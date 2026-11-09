// from server: 44% by atomic.potato
struct S {
    int f(int, int, int, int, int, int, int, int, int, int, int);
};

extern "C" void helper_00802d90(void*, int);

int S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    int local[10];
    *(int*)this = 0;
    local[0] = a1;
    local[2] = 0;
    local[8] = 0;
    if (a9) {
        local[2] = a9;
        helper_00802d90(&local[4], 0);
    }
    helper_00802d90(this, 0);
    local[4] = -1;
    if (a1) {
        int* p = *(int**)a1;
        if (p) {
            ((void (__stdcall*)(int*, int))p)(&local[10], 2);
        }
    }
    return (int)this;
}
