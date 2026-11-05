// from server: 61% by atomic.potato
struct S
{
    void __cdecl f(int);
};

extern "C" int __cdecl sub_4e8410(void *);
extern "C" int __cdecl sub_4e1c10(int, int);

void __cdecl S::f(int a)
{
    char v[48];
    int b = sub_4e8410(v);
    sub_4e1c10(a, b);
}
