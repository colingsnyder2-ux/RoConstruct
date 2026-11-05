// from server: 100% by atomic.potato
extern "C" void __stdcall Target(void*);

struct S
{
    void f(unsigned char value);
};

void S::f(unsigned char value)
{
    if (value != *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0xdd))
    {
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0xdd) = value;
        *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&value) + 3) = 0x00b7b200;
        Target(reinterpret_cast<void*>(0x0040c080));
    }
}
