// from server: 73% by colin
struct S {
    char pad0[0x10];
    int* p10;
    char pad14[0x0C];
    int* p20;
    char pad24[0x0C];
    int* p30;
    char pad34[0x1C];
    int v50;
    void f();
};

void S::f()
{
    int v = v50;
    *p10 = v;
    *p20 = v;
    *p30 = v - v;
}
