// from server: 53% by atomic.potato
extern "C" void __stdcall _invalid_parameter_noinfo();

struct S {
    char pad[8];
    int* begin;
    int* end;
    int f(int index, int* out);
};

int S::f(int index, int* out) {
    int count = (end - begin) >> 2;
    if ((unsigned)index >= (unsigned)count) {
        _invalid_parameter_noinfo();
    }
    *out = begin[index];
    return (int)begin;
}
