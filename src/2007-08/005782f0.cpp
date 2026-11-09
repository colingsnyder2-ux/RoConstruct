// from server: 100% by colin
struct S {
    char pad[0x1d4];
    unsigned char value1d4;
    void setValue(unsigned char v);
};

void S::setValue(unsigned char v)
{
    if (v == this->value1d4)
        return;
    this->value1d4 = v;
    extern void __stdcall sub_444710(unsigned int);
    sub_444710(0x8c2974);
}
