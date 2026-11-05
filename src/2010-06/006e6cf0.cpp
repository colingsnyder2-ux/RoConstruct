// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S
{
    int f(int);
};

extern "C" void __cdecl sub_721e80(int, void *, void *);

int S::f(int a)
{
    sub_721e80(a, (char *)this + 0xa8, (char *)this + 0xb0);
    return a;
}