// from server: 59% by atomic.potato
extern "C" void __stdcall sub_414da0(void*);

struct S
{
    char pad[0xc0];
    unsigned char value;
    void f(unsigned char);
};

void S::f(unsigned char value)
{
    if (value != *(unsigned char*)((char*)this + 0xc0))
    {
        *(unsigned char*)((char*)this + 0xc0) = value;
        sub_414da0((void*)0xe206dc);
        sub_414da0((void*)0xe20ecc);
    }
}
