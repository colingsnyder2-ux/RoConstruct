// from server: 63% by atomic.potato
struct S {
    char pad0[0x68];
    int* begin;
    int* end;
    int f(int);
};

extern "C" int* __stdcall sub_58ee20(int*);

int S::f(int a) {
    int* p = sub_58ee20(&a);
    int idx = *p;
    if (idx < 0)
        return 0;
    int count = (int)((end - begin) >> 2);
    if ((unsigned)idx >= (unsigned)count)
        return 0;
    return begin[idx];
}
