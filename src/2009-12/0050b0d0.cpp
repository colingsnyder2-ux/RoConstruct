// from server: 100% by atomic.potato
struct S
{
    unsigned char value;
    void f(unsigned char);
};

extern "C" void __stdcall Call(unsigned long);

void S::f(unsigned char a)
{
    if (a != *(unsigned char*)((char*)this + 0xb0))
    {
        *(unsigned char*)((char*)this + 0xb0) = a;
        Call(0xb7e808);
    }
}
