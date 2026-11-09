// from server: 6% by atomic.potato
struct S {
    int f(int, int, int);
};

extern "C" int __stdcall sub_7a0950(int);
extern "C" int __stdcall sub_7a0a60(int, int, int);
extern "C" int __stdcall sub_7a1330(int, int, int);
extern "C" int __stdcall sub_7a1490(int, int, int, int, int, int);
extern "C" int __stdcall sub_7a1520(int, int, int);

int S::f(int a, int b, int c) {
    int v = c / 28;
    sub_7a1490(0, 0, 0, 0, 0, 0);
    return 0;
}
