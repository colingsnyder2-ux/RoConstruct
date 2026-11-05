// from server: 84% by atomic.potato
struct W4ChatOption {
    char pad0[0x68];
    int* begin;
    int* end;
    int get(int);
};

extern "C" int* __cdecl sub_4cec50(int*);

int W4ChatOption::get(int a)
{
    int* p = sub_4cec50((int*)((char*)a + 4));
    int v = *p;
    if (v < 0)
        return 0;
    int n = (int)(end - begin);
    if ((unsigned)v >= (unsigned)n)
        return 0;
    return begin[v];
}
