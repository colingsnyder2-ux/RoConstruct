// from server: 34% by colin
struct CIDEDocManager {
    char pad[0x24];
    void* field24;
};

extern "C" void __stdcall sub_448C10();

extern "C" void __stdcall sub_448CE0(CIDEDocManager* self) {
    void* g = *(void**)0x8BBE94;
    *(void**)0x8BBE94 = 0;
    if (g != 0) {
        void** vtbl = *(void***)g;
        ((void (__stdcall*)(void*, int))vtbl[0])(g, 1);
    }
    void* p = self->field24;
    void** vtbl2 = *(void***)p;
    ((void (__stdcall*)(void*, int, int))vtbl2[0x88 / 4])(p, 0, 1);
    sub_448C10();
}
