// from server: 100% by colin
extern "C" void __cdecl _free(void*);
extern "C" void __stdcall _op_delete(void*, unsigned int, int, void (*)(void*));

struct CRegObject {
    void Cleanup(void* p);
};

void CRegObject::Cleanup(void* p)
{
    if (p == 0)
        return;

    void* a = *(void**)((char*)p + 0xc);
    if (a != 0) {
        void** vt = *(void***)a;
        void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vt[2];
        fn(a);
    }

    void* b = *(void**)((char*)p + 0x14);
    *(void**)((char*)p + 0xc) = 0;
    if (b != 0) {
        int n = *(int*)((char*)b - 4);
        void* base = (char*)b - 4;
        _op_delete(b, 0xc, n, (void (*)(void*))0x4023b0);
        _free(base);
    }
    *(void**)((char*)p + 0x14) = 0;
}
