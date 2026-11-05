// from server: 23% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    ((char*)this)[0x14] = 1;
    ((char*)this)[0x15] = 1;
}
