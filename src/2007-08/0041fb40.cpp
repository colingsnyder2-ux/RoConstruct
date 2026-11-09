// from server: 100% by colin
struct CSelectionTreeCtrl {
    void* field0;
    void* field4;
    void InsertItem(void* item, void* parent);
};

extern "C" void* __stdcall sub_62FF02(void* a, void* b, void* c);
extern "C" void __fastcall sub_41EEB0(void* p);

void CSelectionTreeCtrl::InsertItem(void* item, void* parent) {
    void* a = item;
    if (a != 0) {
        a = *(void**)((char*)a + 4);
    }
    void* b = parent;
    void* c = *(void**)((char*)this + 4);
    void* r = sub_62FF02(c, a, b);
    void* q = *(void**)((char*)r + 0x94);
    void* v = *(void**)q;
    sub_41EEB0(v);
}
