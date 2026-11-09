// from server: 43% by atomic.potato
struct S {
    char pad[0xb0];
    int* begin;
    int* end;
    int f(int);
};

extern "C" int __stdcall sub_62E750(int*);
extern "C" void __stdcall _invalid_parameter_noinfo();

int S::f(int a) {
    int* p = (int*)sub_62E750(&a);
    int idx = *p;
    if (idx < 0)
        return 0;
    int n = (int)(end - begin);
    if ((unsigned)idx >= (unsigned)n)
        return 0;
    if ((unsigned)idx >= (unsigned)(end - begin))
        _invalid_parameter_noinfo();
    return begin[idx];
}
