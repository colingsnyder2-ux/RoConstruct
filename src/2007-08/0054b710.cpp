// from server: 100% by colin
struct UString_sink
{
    char pad[0x58];
    unsigned int flags;
    void setFlag(bool value);
};

void UString_sink::setFlag(bool value)
{
    unsigned int v = value ? 0x10u : 0u;
    flags = (flags & 0xffffffefu) | v;
}
