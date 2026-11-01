// from server: 100% by colin
struct RBX_VSpecialShape_FactoryProduct {
    char pad[0xe8];
    int value;
    void setValue(int);
};

void RBX_VSpecialShape_FactoryProduct::setValue(int v)
{
    if (value != v) {
        value = v;
        extern void __stdcall func_00444710(int);
        func_00444710(0x8c2e8c);
    }
}
