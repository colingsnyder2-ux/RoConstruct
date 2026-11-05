// from server: 100% by colin
struct S {
    int field_0;
    int pad0;
    int pad1;
    int field_c;
    S* init(int arg);
};

extern void __fastcall sub_00648640(void* self);

S* S::init(int arg)
{
    sub_00648640(this);
    field_0 = arg;
    field_c = 1;
    return this;
}
