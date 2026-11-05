// from server: 69% by atomic.potato
extern "C" void __stdcall UpdateVTeamProduct(void *, unsigned int);

struct VTeamFactoryProduct
{
    void SetValue(unsigned char);
};

void VTeamFactoryProduct::SetValue(unsigned char value)
{
    if (value != *(unsigned char *)((char *)this + 0x88))
    {
        *(unsigned char *)((char *)this + 0x88) = value;
        UpdateVTeamProduct(this, 0x00e2d100);
    }
}
