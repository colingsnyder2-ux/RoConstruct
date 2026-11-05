// from server: 83% by atomic.potato
struct S {
    char pad0[0x68];
    int* begin;
    int* end;
    int get(int);
};

extern "C" int* __cdecl sub_5c43c0(int);

int S::get(int a) {
    int* p = sub_5c43c0(a);
    int v = *p;
    if (v < 0) return 0;
    int n = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)v >= (unsigned)n) return 0;
    return begin[v];
}
