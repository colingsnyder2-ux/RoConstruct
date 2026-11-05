// from server: 100% by tester
struct CXTPPropertyGridPaintManager {
    char pad[96];
    void* field_0x20;

    void func_006f8f10(void* arg);
};

extern "C" void* __fastcall sub_682a20(void*);
extern "C" char __fastcall sub_738412(void*);

void CXTPPropertyGridPaintManager::func_006f8f10(void* arg)
{
    void* p = sub_682a20(field_0x20);
    char flags = sub_738412(p);
    if (flags & 0x20) {
        void* v = *(void**)((char*)arg + 0x14);
        void** vtbl = *(void***)v;
        void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vtbl[0x74 / 4];
        fn(arg);
    }
}
