// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S {
    int pad[4];
    void (__thiscall *m10)(int, float, float, float, float);
    int m14;
    int m18;
    void f(float a, float b, float c, float d);
};
void S::f(float a, float b, float c, float d)
{
    m10(m14 + m18, a, b, c, d);
}