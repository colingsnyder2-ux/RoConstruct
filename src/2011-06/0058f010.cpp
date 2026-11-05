// from server: 83% by atomic.potato
extern "C" int* __cdecl sub_0058ee20(int);

struct S {
    char pad_0000[0x68];
    int* begin;
    int* end;
    int f(int);
};

int S::f(int a) {
    int* p = sub_0058ee20(a);
    int v = *p;
    if (v < 0) return 0;
    int n = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)v >= (unsigned)n) return 0;
    return begin[v];
}
