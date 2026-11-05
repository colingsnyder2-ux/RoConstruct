// from server: 40% by atomic.potato
extern "C" int __stdcall sub_a951e0(int, int, int, int);

struct S {
    int __cdecl f(int);
};

int S::f(int a) {
    double d;
    int x = 0;
    int y = 0;
    int z = 0;
    sub_a951e0(a, 0x200, 0, (int)&d);
    *(double*)y = d;
    return 0;
}
