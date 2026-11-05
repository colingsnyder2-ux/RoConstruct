// from server: 100% by tester
struct CXTPRibbonGroupControlPopup {
    char pad[0x100];
    void* field_fc;
    void OnPopup(int);
};

extern "C" void* __fastcall sub_00643a40(void*);

void CXTPRibbonGroupControlPopup::OnPopup(int a)
{
    void* p = sub_00643a40(field_fc);
    void** vt = *(void***)p;
    typedef void (__thiscall *Fn)(void*, int*, int, void*, int);
    Fn fn = (Fn)vt[0x144 / 4];
    int local[2];
    fn(p, local, a, this, 1);
}
