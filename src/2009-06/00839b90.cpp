// from server: 100% by tester
struct S
{
    void f(void* p);
};

void S::f(void* p)
{
    if (*(unsigned char*)((char*)this + 0x274) == 0)
    {
        typedef void (__thiscall *Fn)(S*, void*);
        Fn fn = *(Fn*)((char*)*(void**)this + 0xd4);
        fn(this, p);
        *(unsigned char*)((char*)this + 0x274) = 1;
    }
}
