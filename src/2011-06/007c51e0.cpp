// from server: 79% by atomic.potato
extern "C" void __cdecl sub_7599C0(void *, int, int);

struct S {
    S *f(int, int);
    int value;
    int fieldCC;
};

S *S::f(int a, int b)
{
    sub_7599C0(this, a, b);
    fieldCC = 0;
    value = 0xABD59C;
    return this;
}
