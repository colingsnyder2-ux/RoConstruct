// from server: 100% by colin
struct S {
    char pad[0x1a0];
    unsigned char value1a0;
    void setValue(unsigned char v);
};

void S::setValue(unsigned char v)
{
    if (v == this->value1a0)
        return;
    this->value1a0 = v;
    extern void __stdcall sub_444710(unsigned int);
    sub_444710(0x8c28e0);
}
