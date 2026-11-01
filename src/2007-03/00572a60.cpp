// from server: 100% by tester
struct S {
    char pad[0x1e0];
    char* ptr;
    char get() const;
};

char S::get() const
{
    return *(char*)(ptr + 0x70);
}