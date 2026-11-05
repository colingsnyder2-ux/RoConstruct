// from server: 100% by atomic.potato
struct S
{
    unsigned char f();
};

unsigned char S::f()
{
    return *(((unsigned char*)*(int*)((char*)this + 0x168)) + 0x80);
}
