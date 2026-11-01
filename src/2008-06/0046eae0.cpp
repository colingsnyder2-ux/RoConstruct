// from server: 100% by king_originala
extern void (__thiscall *destroyString)(void *);
void __cdecl operator delete(void *) throw();

struct VTableCleanup {
    unsigned long *slot;
    VTableCleanup(unsigned long *p);
    ~VTableCleanup();
};

inline VTableCleanup::VTableCleanup(unsigned long *p) : slot(p)
{
    *slot = 0x0081ca0c;
}

inline VTableCleanup::~VTableCleanup()
{
    *slot = 0x0081ca00;
}

struct S {
    unsigned long vtable;
    char padding[108];
    char stringStorage[28];

    void *destroy(unsigned int flags);
};

void *S::destroy(unsigned int flags)
{
    {
        VTableCleanup cleanup(&vtable);
        destroyString(stringStorage);
    }

    if (flags & 1)
        operator delete(this);

    return this;
}
