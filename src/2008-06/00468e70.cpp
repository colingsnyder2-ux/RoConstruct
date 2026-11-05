// from server: 100% by colin
struct DxUserInput
{
    char pad0[0x28];
    void sub1();
    void sub2();
    void f(int a, int b, int c);
};

void DxUserInput::f(int a, int b, int c)
{
    DxUserInput* p = this - 1;
    p->sub1();
    p->sub2();
}
