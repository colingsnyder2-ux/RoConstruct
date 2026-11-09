// from server: 100% by colin
struct S {
};

struct T {
    void g(int a);
};

extern "C" int __cdecl sub_005bda90(int a, int b);
extern "C" int __cdecl sub_005bdf20(int a, int b);
extern "C" int __cdecl sub_005bde00(int a, int b, int c);
extern "C" int __cdecl sub_005bd850(int a, int b, int c);
extern "C" int __cdecl sub_005bd590(int a, int b);
extern int dword_008abe74;

bool __cdecl f(int a, int b, int c)
{
    int v = sub_005bda90(a, b);
    if (v) {
        if (sub_005bdf20(a, b)) {
            sub_005bde00(a, -10000, dword_008abe74);
            if (sub_005bd850(a, -1, -2)) {
                sub_005bd590(a, -3);
                ((T*)c)->g(v);
                return true;
            }
        } else {
            sub_005bd590(a, -2);
        }
    }
    return false;
}
