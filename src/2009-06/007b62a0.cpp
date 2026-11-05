// from server: 100% by tester
struct CXTPMenuBar_CControlMDIButton
{
    void f();
};

extern "C" void* __cdecl sub_00646570();
extern "C" void* __cdecl sub_006306BE(void*);
extern "C" void* __cdecl sub_00630202(void*);

void CXTPMenuBar_CControlMDIButton::f()
{
    void* p = sub_00646570();
    void* q = sub_006306BE(p);
    void* r = sub_00630202(q);
    if (r != 0)
    {
        if (*(int*)((char*)r + 0x20) != 0)
        {
            void** vt = *(void***)r;
            void (__thiscall *fn)(void*, int) = (void (__thiscall *)(void*, int))vt[0x184 / 4];
            fn(r, 0);
        }
    }
    *(int*)((char*)this + 0x1c0) = 0;
}
