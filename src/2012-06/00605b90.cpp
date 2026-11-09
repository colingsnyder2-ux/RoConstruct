// from server: 58% by atomic.potato
struct S_func_00605b90 {
};

void __cdecl f(int *a1, int *a2, int *a3)
{
    while (a1 != a2) {
        if (a3 != 0)
            *a3 = *a1;
        ++a1;
        ++a3;
    }
}
