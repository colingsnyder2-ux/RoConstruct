// from server: 100% by colin
struct S {
};

struct T {
    void g(int);
};

extern "C" int __cdecl sub_5BDA90(int, int);
extern "C" int __cdecl sub_5BDF20(int, int);
extern "C" int __cdecl sub_5BDE00(int, int, int);
extern "C" int __cdecl sub_5BD850(int, int, int);
extern "C" int __cdecl sub_5BD590(int, int);

extern int dword_8ABE80;

char __cdecl f(int a, int b, int c)
{
    int v = sub_5BDA90(a, b);
    if (v == 0)
        return 0;

    if (sub_5BDF20(a, b) != 0)
    {
        sub_5BDE00(a, -10000, dword_8ABE80);
        if (sub_5BD850(a, -1, -2) != 0)
        {
            sub_5BD590(a, -3);
            ((T*)c)->g(v);
            return 1;
        }
        return 0;
    }

    sub_5BD590(a, -2);
    return 0;
}
