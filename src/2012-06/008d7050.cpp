// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct T { };
struct S
{
    int a, b, c;
    void (T::*pmf)(int, float, float);
    T *obj;
    void f(int, float, float);
};
void S::f(int a, float b, float c)
{
    (obj->*pmf)(a, b, c);
}