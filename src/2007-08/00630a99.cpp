// from server: 40% by colin
extern "C" void __stdcall sub_631620();

void __cdecl sub_630a99(int a, int b, int c, int d, void (__cdecl *fn)())
{
    sub_631620();
    d--;
    if (d >= 0) {
        a -= b;
        fn();
    }
}
