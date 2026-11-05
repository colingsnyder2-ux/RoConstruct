// from server: 69% by atomic.potato
struct S {
    char pad[0x68];
    int* begin;
    int* end;
    int f(int);
};

extern "C" int* __cdecl sub_5c7b60(int*);

int S::f(int a) {
    int* p = sub_5c7b60(&a + 1);
    int idx = *p;
    if (idx < 0)
        return 0;
    int count = (int)(end - begin);
    if ((unsigned)idx >= (unsigned)count)
        return 0;
    return begin[idx];
}
