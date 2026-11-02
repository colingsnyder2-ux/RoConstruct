// from server: 100% by tajop
struct Desc;
extern const Desc g_desc;
struct Signal
{
    void fire(const Desc* d);
};
struct S
{
    char pad0[0xa0];
    int value;
    char pad1[0x144 - 0xa4];
    Signal changed;
    void set(int v);
};
void S::set(int v)
{
    if (v != value)
    {
        value = v;
        changed.fire(&g_desc);
    }
}
