// from server: 39% by colin
struct Vec {
    char pad[4];
    int* begin;
    int* end;
};

struct S {
    char pad[0x44];
    Vec v;
    int f(int);
};

int S::f(int a) {
    Vec* p = &v;
    int n = (int)((p->end - p->begin) * 0x2AAAAAABLL >> 35);
    n += (unsigned)n >> 31;
    return ((int (__thiscall*)(Vec*, int))0x4fe210)(p, a + n);
}
