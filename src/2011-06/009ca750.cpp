// from server: 28% by atomic.potato
struct S
{
    unsigned char f();
};

unsigned char S::f()
{
    return *((unsigned char *)this + 0x41);
}
