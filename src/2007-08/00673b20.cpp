// from server: 100% by colin
struct CXTPCustomizeSheet {
    char pad[0xb8];
    void* field_b8;
    void SetActivePage(void* page);
};

void CXTPCustomizeSheet::SetActivePage(void* page) {
    void* p = *(void**)((char*)field_b8 + 0x58);
    if (p != 0) {
        int flag = (*(int*)((char*)p + 0x90) > 0) ? 1 : 0;
        void** vtbl = *(void***)page;
        typedef void (__thiscall *Fn)(void*, int);
        ((Fn)vtbl[0])(page, flag);
    }
}
