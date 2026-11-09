// from server: 21% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl malloc(unsigned int);

struct VGuiObject
{
    void addChild(void* child);

    void* __thiscall createChild(int a, int b);
};

struct Child
{
    unsigned char pad0[8];
    void* vptr8;
    unsigned char pad1[4];
    void* vptr0;
    void* vptr8b;
    VGuiObject* owner;
    int field14;
    int field18;
};

void* sub_4bfc10(VGuiObject* self, void* child);

void* __thiscall VGuiObject::createChild(int a, int b)
{
    Child* c = (Child*)malloc(0x20);
    if (c)
    {
        *(unsigned short*)c = 0;
        *(unsigned short*)((char*)c + 2) = 1;
    }
    c = (Child*)((char*)c + 4);
    if (c)
    {
        c->vptr8 = (void*)0xa77580;
        *(int*)((char*)c + 0xc) = 0;
        c->vptr0 = (void*)0xaa349c;
        c->vptr8b = (void*)0xaa3494;
        *(VGuiObject**)((char*)c + 0x10) = this;
        *(int*)((char*)c + 0x14) = *(int*)&a;
        *(int*)((char*)c + 0x18) = *(int*)((char*)&a + 4);
        c->vptr0 = (void*)0xaa36c8;
        c->vptr8b = (void*)0xaa36c0;
    }
    else
    {
        c = 0;
    }
    sub_4bfc10(this, c);
    *(void**)&a = c;
    if (c)
    {
        char* p = (char*)c + 5;
        if (p)
        {
            p = p - 5;
        }
        else
        {
            p = 0;
        }
        volatile long* ref = (volatile long*)(p - 2);
        _InterlockedExchangeAdd(ref, 1);
    }
    return (void*)&a;
}
