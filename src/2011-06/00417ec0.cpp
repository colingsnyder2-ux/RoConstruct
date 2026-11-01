// from server: 100% by colin
extern "C" int __stdcall sub_4067C0(int, int, int, int);

struct S {
    int f(int, int, int);
};

int S::f(int a, int b, int c) {
    return sub_4067C0(a, 0x00A5E94C, b, c);
}
