// from server: 100% by atomic.potato
extern "C" int __cdecl sub_78A770(int, int, int);
extern "C" int __cdecl sub_78A660(int, int, int);
extern "C" int __cdecl sub_7953E0(int, int, int);

extern int dword_B62B78;

struct S {
};

int __cdecl f(int a) {
    int v = sub_78A770(a, 2, 0);
    int w = sub_78A660(a, 1, dword_B62B78);
    sub_7953E0(w, v, a);
    return 0;
}
