// from server: 100% by colin
struct CClassTreeView {
    char pad[0x60];
    void* field60;
    char pad2[0x9c - 0x64];
    unsigned char field9c;
    void func();
};

extern "C" void __fastcall sub_62FCD4(void*);

void CClassTreeView::func() {
    sub_62FCD4(this);
    if (field9c != 0) {
        void* p = field60;
        void (__fastcall *fn)(void*) = *(void (__fastcall **)(void*))((char*)p + 0x44);
        fn((char*)this + 0x60);
    }
}
