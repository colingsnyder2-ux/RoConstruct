// from server: 43% by colin
struct CBrowserView {
    char pad[0x2b0];
    void* field_2b0;
    char pad2[0x4];
    void* field_2b8;
    void sub_40ab50();
    void sub_5465b0();
    void sub_64ee10();
    void sub_62fc62(void*);
    void destroy();
};

extern "C" void __stdcall sub_77ddbc(void*);
extern "C" void __stdcall sub_62fc62_impl(void*);

void CBrowserView::destroy()
{
    *(void**)this = (void*)0x785d3c;
    sub_77ddbc(&field_2b8);
    if (field_2b0) {
        void** vtable = *(void***)field_2b0;
        void (*fn)(void*) = (void (*)(void*))vtable[2];
        fn(field_2b0);
    }
    sub_64ee10();
    sub_5465b0();
    void* p = *(void**)((char*)this + 0xfc);
    sub_62fc62_impl(p);
    *(void**)((char*)this + 0xfc) = 0;
    sub_40ab50();
}
