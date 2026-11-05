// from server: 100% by colin
struct S {
    char pad[0x1d8];
    char* ptr;
    char get() const;
};

char S::get() const
{
    return *(char*)(ptr + 0x70);
}
