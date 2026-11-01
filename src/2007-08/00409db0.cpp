// from server: 100% by colin
struct VCApp_CComObject {
    void* f(int);
};

extern "C" void __cdecl sub_62FC62(void*);
extern "C" void __fastcall sub_409290(void*);

struct GlobalObj_8BAE44 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

extern GlobalObj_8BAE44* g_8BAE44;

void* VCApp_CComObject::f(int arg)
{
    *(int*)((char*)this + 0) = 0x7853b8;
    *(int*)((char*)this + 4) = 0x7853a0;
    *(int*)((char*)this + 8) = 0x78537c;
    *(int*)((char*)this + 0x14) = 0x785364;
    *(int*)((char*)this + 0x1c) = 0x785348;
    *(int*)((char*)this + 0x24) = 0x7852fc;
    *(int*)((char*)this + 0x28) = 0xc0000001;

    GlobalObj_8BAE44* p = g_8BAE44;
    p->v2();

    sub_409290(this);

    if (arg & 1)
        sub_62FC62(this);

    return this;
}
