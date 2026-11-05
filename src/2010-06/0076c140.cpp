// from server: 33% by atomic.potato
struct S {
    char pad0[0x1c];
    char field1c[0x20];
    char field3c;
    char field3d;
    S* ctor(const S* other);
};

extern "C" void __stdcall G1_func_009ea40c();
extern "C" void __stdcall G2_func_0076bac0();

S* S::ctor(const S* other)
{
    G1_func_009ea40c();
    G2_func_0076bac0();
    field3c = other->field3c;
    field3d = other->field3d;
    return this;
}
