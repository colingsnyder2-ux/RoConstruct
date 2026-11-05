// from server: 70% by atomic.potato
extern "C" void __cdecl sub_411f60(int);

struct VPlayer
{
    char pad[0xd8];
    int field_d8;
    void set(int value);
};

void VPlayer::set(int value)
{
    int a = 0x190;
    int b = 0;
    int* p = &a;
    if (value <= a)
        p = &value;
    if (*p <= 0)
        p = &b;
    int v = *p;
    if (v != field_d8)
    {
        field_d8 = v;
        sub_411f60(0xcb7ccc);
    }
}
