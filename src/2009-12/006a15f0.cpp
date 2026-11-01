// from server: 100% by atomic.potato
extern "C" int __cdecl sub_78a770(int, int, int);
extern "C" int __cdecl sub_78a660(int, int, int);
extern "C" int __cdecl sub_7952c0(int, int, int);

extern int dword_B62B74;

struct S {
};

int __cdecl f(int a) {
    int v = sub_78a770(a, 2, 0);
    int w = sub_78a660(a, 1, dword_B62B74);
    sub_7952c0(w, v, a);
    return 0;
}
