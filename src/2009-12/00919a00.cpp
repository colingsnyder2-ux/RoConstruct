// from server: 44% by atomic.potato
struct S
{
    unsigned char f();
};

unsigned char S::f()
{
    return *((unsigned char *)this + 0xa9);
}
