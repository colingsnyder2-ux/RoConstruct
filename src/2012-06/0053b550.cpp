// from server: 100% by atomic.potato
extern "C" void __stdcall SetPersistentDataStoreValue(unsigned int);

struct S
{
    unsigned char value;
    void f(unsigned char);
};

void S::f(unsigned char value)
{
    if (value != *(unsigned char*)((char*)this + 0x8c))
    {
        *(unsigned char*)((char*)this + 0x8c) = value;
        SetPersistentDataStoreValue(0xe21244);
    }
}
