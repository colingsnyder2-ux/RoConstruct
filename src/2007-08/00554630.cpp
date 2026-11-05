// from server: 100% by colin
struct RBX_VTeam_FactoryProduct {
    char pad[0xf0];
    unsigned char field_f0;
    void setAutoAssignable(bool value);
};

void RBX_VTeam_FactoryProduct::setAutoAssignable(bool value)
{
    field_f0 = (unsigned char)value;
    extern void __stdcall func_00444710(int);
    func_00444710(0x8c1cf8);
}
