// from server: 100% by atomic.potato
struct PlayerGui
{
    void setValue(unsigned char value);
};

extern "C" void __stdcall G1_func_0040c470(unsigned int value);

void PlayerGui::setValue(unsigned char value)
{
    if (*((unsigned char *)this + 0xad) != value)
    {
        *((unsigned char *)this + 0xad) = value;
        G1_func_0040c470(0x00c1cbdc);
    }
}
