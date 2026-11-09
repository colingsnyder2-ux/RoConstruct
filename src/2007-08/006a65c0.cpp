// from server: 100% by colin
struct CXTPMenuBar_CControlMDISysMenuPopup {
    char pad0[0x17c];
    void* m_pIcon;
    void* dtor(int flags);
};

extern "C" int (__stdcall *DestroyIcon)(void*);
extern "C" void __fastcall sub_00670590(void*);
extern "C" void __cdecl sub_0062FC62(void*);

void* CXTPMenuBar_CControlMDISysMenuPopup::dtor(int flags)
{
    void* p = m_pIcon;
    *(int*)this = 0x7d421c;
    *(int*)((char*)this + 0x20) = 0x7d41bc;
    if (p != 0) {
        DestroyIcon(p);
    }
    sub_00670590(this);
    if (flags & 1) {
        sub_0062FC62(this);
    }
    return this;
}
