// from server: 94% by atomic.potato
struct S {
    int f(int*);
};

int S::f(int* p)
{
    --p[7];
    int n = p[7];
    if (n == 0 && p != 0) {
        int** q = (int**)(p + 4);
        void (__thiscall *fn)(void*, int) =
            (void (__thiscall *)(void*, int))q[0][5];
        fn((void*)q, 1);
    }
    return n;
}
