// from server: 69% by atomic.potato
struct S {
    char pad_00[0x68];
    int* begin;
    int* end;
    int f(int);
};

extern "C" int* __cdecl sub_005A11A0(int*);

int S::f(int a)
{
    int* p = sub_005A11A0(&a + 1);
    int v = *p;
    if (v < 0)
        return 0;
    int n = (int)(end - begin);
    if ((unsigned)v >= (unsigned)n)
        return 0;
    return begin[v];
}
