// from server: 25% by atomic.potato
struct ConstraintSurfacePair
{
    int vtable;
    int field4;
    int field8;
    int fieldC;
    int field10;

    void f(int a, int b, int* c, int* d);
};

void ConstraintSurfacePair::f(int a, int b, int* c, int* d)
{
    field4 = a;
    field8 = b;
    vtable = 0xbe0658;
    fieldC = *c;
    field10 = *d;
    vtable = 0xbe0698;
}
