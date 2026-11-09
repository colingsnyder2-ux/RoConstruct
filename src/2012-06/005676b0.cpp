// from server: 90% by atomic.potato
extern "C" void __cdecl ImportedFunction(void*, const char*, unsigned int);

struct S
{
    int field0;
    unsigned int field4;
    int field8;
    void* fieldC;
    unsigned char field10;

    void f();
};

void S::f()
{
    if (field10 && field4 > 0x800)
        ImportedFunction(fieldC, "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\Network\\raknet\\Source\\BitStream.cpp", 0x86);
}
