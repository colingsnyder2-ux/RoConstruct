// from server: 100% by colin
struct CClassTreeView {
    char pad[0x60];
    void* field_60;
    int FindItem(int item);
};

extern "C" int __stdcall sub_630646(int item);

int CClassTreeView::FindItem(int item)
{
    int result = sub_630646(item);
    if (result == -1)
        return result;
    void** vt = (void**)((char*)field_60 + 0x44);
    typedef int (__thiscall *Fn)(void*);
    Fn fn = (Fn)vt[0];
    fn((char*)this + 0x60);
    return 0;
}
