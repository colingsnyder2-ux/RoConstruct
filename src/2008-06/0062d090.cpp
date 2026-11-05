// from server: 100% by tester
struct S {
    bool f(int);
};

extern "C" int __cdecl sub_6A17C6(int, int, int, int, int);

bool S::f(int a) {
    int r = sub_6A17C6(a, 0, 0x92907c, 0x9481b8, 0);
    return r == 0;
}
