// from server: 100% by atomic.potato
struct Humanoid {
    char pad[0x1e6];
    unsigned char field_1e6;
    void setFlag(unsigned char value);
};

void Humanoid::setFlag(unsigned char value)
{
    if (field_1e6 != value)
    {
        field_1e6 = value;
        extern void __stdcall notifyChange(unsigned long);
        notifyChange(0xa4da90);
    }
}
