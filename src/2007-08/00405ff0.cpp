// from server: 100% by colin
extern "C" int __stdcall sub_4022A0(int, int, int, int);

struct S {
    int f(int, int, int);
};

int S::f(int a, int b, int c) {
    return sub_4022A0(a, 0x784e28, b, c);
}
