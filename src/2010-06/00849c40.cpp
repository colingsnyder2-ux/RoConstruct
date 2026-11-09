// from server: 100% by tester
struct CXTPControlQuickAccessMorePopup {
    char pad[0x100];
    void* field_fc;
    void OnClick(int);
};

struct Helper {
    void* GetItem();
};

extern "C" void* __fastcall sub_6a79e0(void*);

void CXTPControlQuickAccessMorePopup::OnClick(int arg)
{
    Helper* h = (Helper*)sub_6a79e0(field_fc);
    void** vt = *(void***)h;
    void (__thiscall *fn)(void*, int, void*) = (void (__thiscall *)(void*, int, void*))vt[0x168/4];
    fn(h, arg, this);
}
