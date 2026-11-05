// from server: 100% by colin
struct S {
    char pad[0x190];
    int field_190;
    void func_005784e0(int);
};

extern void __stdcall func_00444710(int);

void S::func_005784e0(int value)
{
    if (value != this->field_190) {
        this->field_190 = value;
        func_00444710(0x8c2a98);
    }
}
