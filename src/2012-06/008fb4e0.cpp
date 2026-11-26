// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct T { void g(); };
struct S
{
    char pad[0x2c];
    char *p;
    void f(char *x);
};

void S::f(char *x)
{
    int off = x ? (int)x - 0x1c : 0;
    ((T *)(p + off))->g();
}