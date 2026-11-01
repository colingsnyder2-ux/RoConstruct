// from server: 100% by colin
struct CXTPRibbonSystemPopupBar {
    void* m(void* arg);
};

extern "C" void* __fastcall sub_71ABB0(CXTPRibbonSystemPopupBar* self);

void* CXTPRibbonSystemPopupBar::m(void* arg)
{
    void* p = sub_71ABB0(this);
    void* vtable = *(void**)p;
    void (__thiscall* fn)(void*, void*, void*) = *(void (__thiscall**)(void*, void*, void*))((char*)vtable + 0x1c8);
    fn(p, this, arg);
    return p;
}
