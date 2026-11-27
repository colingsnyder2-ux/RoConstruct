// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern unsigned char flag;
struct T { void call(float); };
struct S { void f(float); };
void S::f(float value)
{
    if (flag) return;
    void *p = *(void **)((char *)this + 0x84);
    int q = *(int *)p;
    ((T*)((char *)this + 0x84 + q))->call(value);
}
