// from server: 100% by colin
struct S {
    char pad[0x1d5];
    unsigned char value1d5;
    void setValue(unsigned char v);
};

void S::setValue(unsigned char v)
{
    if (v == this->value1d5)
        return;
    this->value1d5 = v;
    extern void __stdcall sub_444710(unsigned char);
    sub_444710(0x8c27f4);
}
