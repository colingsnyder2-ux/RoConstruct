// from server: 95% by atomic.potato
extern "C" void __cdecl SetPersistentDataStoreValue(unsigned int);

struct S
{
    void f(unsigned int);
};

void S::f(unsigned int value)
{
    if (value != *(unsigned int*)((char*)this + 0x88))
    {
        *(unsigned int*)((char*)this + 0x88) = value;
        SetPersistentDataStoreValue(0xe208c4);
    }
}
