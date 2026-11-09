// from server: 96% by atomic.potato
struct S {
    int f(int a, int b);
};

extern bool func_00704780(int*);

int S::f(int a, int b)
{
    int local[2];
    local[0] = a;
    local[1] = b;
    if (!func_00704780(local)) {
        int* p = (int*)((char*)this + 8);
        if (p) {
            p[0] = local[0];
            p[1] = local[1];
        }
        *(int*)this = 0xc4ae84;
    } else {
        *(int*)this = 0;
    }
    return 0;
}
