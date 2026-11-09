// from server: 100% by atomic.potato
struct S
{
    unsigned char f();
};

unsigned char S::f()
{
    return *reinterpret_cast<unsigned char*>(
        *reinterpret_cast<unsigned char**>(
            reinterpret_cast<unsigned char*>(this) + 0x168) + 0x101);
}
