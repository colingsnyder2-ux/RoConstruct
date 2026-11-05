// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
extern "C" int __cdecl sub_520650(int);
extern "C" void __cdecl sub_51E8E0(int, const char*);

int __cdecl sub_521720(int a, int b)
{
    int v = sub_520650(b);
    if ((unsigned)v > 0x7fffffff)
    {
        sub_51E8E0(a, "PNG unsigned integer out of range.\n");
    }
    return v;
}
