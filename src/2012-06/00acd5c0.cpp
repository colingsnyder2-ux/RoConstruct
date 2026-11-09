// from server: 54% by Intel
struct seg_00ac0000
{
    void func_00acd5c0();
};

void seg_00ac0000::func_00acd5c0()
{
    unsigned char *ebx;
    unsigned char dl;
    unsigned char bh;

    --*reinterpret_cast<signed char *>(ebx - 0x6816FBB3);
    dl = bh;
    ++ebx;
}
