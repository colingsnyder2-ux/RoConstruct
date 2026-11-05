// from server: 100% by why2
struct S
{
    char pad[0xb0];
    unsigned int field;
    int get() const;
};

int S::get() const
{
    return (field >> 2) & 1;
}
