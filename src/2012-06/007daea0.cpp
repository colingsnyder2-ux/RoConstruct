// from server: 63% by atomic.potato
extern "C" void Call785560(void*);

struct S
{
    void f(void*);
};

void S::f(void* p)
{
    char* base = *(char**)((char*)this + 0x2c);
    if (p)
        Call785560(base + ((long)p - 0x1c));
    else
        Call785560(base);
}
