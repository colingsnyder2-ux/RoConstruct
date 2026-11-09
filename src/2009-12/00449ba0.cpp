// from server: 84% by atomic.potato
extern "C" void __stdcall Function0040C080(unsigned char value);

struct S
{
    void f(unsigned char value);
};

void S::f(unsigned char value)
{
    if (value != *(unsigned char*)((char*)this + 0xfa))
    {
        *(unsigned char*)((char*)this + 0xfa) = value;
        Function0040C080(value);
    }
}
