// from server: 100% by atomic.potato
extern "C" void __stdcall Function_411f60(void*);

struct S
{
    unsigned char value;
    void f(unsigned char);
};

void S::f(unsigned char v)
{
    if (v != *(unsigned char*)((char*)this + 0x180))
    {
        *(unsigned char*)((char*)this + 0x180) = v;
        Function_411f60((void*)0x00cce088);
    }
}
