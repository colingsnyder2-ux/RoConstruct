// from server: 32% by colin
struct S {
    void f(int a, int b, int c, int d, int e);
};

extern "C" void __cdecl sub_631620(int);
extern "C" void __cdecl sub_631665();
extern "C" void __cdecl sub_630c29();

void S::f(int a, int b, int c, int d, int e)
{
    sub_631620(0x10);
    int i = 0;
    while (i >= e) {
        (*(void (__cdecl **)(int))(d))(a);
        a += b;
        i++;
    }
    sub_630c29();
    sub_631665();
}
