// from server: 63% by atomic.potato
extern "C" void* __stdcall Ogre_removeChild(void*, unsigned int);

struct S
{
    void* f(unsigned int);
};

void* S::f(unsigned int value)
{
    void* child = Ogre_removeChild(this, value);
    return ((void* (__thiscall *)(S*, void*))0x50ecf0)(this, child);
}
