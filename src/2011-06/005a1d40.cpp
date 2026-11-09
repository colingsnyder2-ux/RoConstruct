// from server: 69% by atomic.potato
struct S {
    char pad0[0x68];
    int* begin;
    int* end;
    int f(int);
};

extern int G1_func_005a17c0(int*);

int S::f(int a)
{
    int* p = (int*)G1_func_005a17c0((int*)((char*)&a + 4));
    int v = *p;
    if (v < 0)
        return 0;
    int n = (int)(end - begin);
    if ((unsigned)v >= (unsigned)n)
        return 0;
    return begin[v];
}
