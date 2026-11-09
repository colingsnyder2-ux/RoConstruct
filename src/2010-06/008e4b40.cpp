// from server: 100% by atomic.potato
struct S
{
    void f(void* p);
};

void S::f(void* p)
{
    if (*(unsigned char*)((char*)this + 0x298) == 0)
    {
        typedef void (__thiscall *Fn)(S*, void*);
        Fn fn = *(Fn*)((char*)*(void**)this + 0xe8);
        fn(this, p);
        *(unsigned char*)((char*)this + 0x298) = 1;
    }
}
