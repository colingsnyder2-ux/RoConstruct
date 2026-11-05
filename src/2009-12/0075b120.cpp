// from server: 75% by atomic.potato
extern "C" void __cdecl Notify(unsigned long);

struct S
{
    void Set(bool value);
    unsigned char padding[0x1cc];
    unsigned char field_1cc;
};

void S::Set(bool value)
{
    if (field_1cc != (unsigned char)value)
    {
        field_1cc = (unsigned char)value;
        Notify(0x00b97778);
    }
}
