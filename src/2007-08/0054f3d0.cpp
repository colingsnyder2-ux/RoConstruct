// from server: 100% by colin
struct S {
    unsigned char pad[0x9c];
    unsigned int flags;
    unsigned int get() const;
};

unsigned int S::get() const
{
    return (flags >> 4) & 1;
}
