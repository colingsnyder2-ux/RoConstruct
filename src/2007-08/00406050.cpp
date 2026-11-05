// from server: 36% by colin
extern "C" void* __cdecl sub_62FEF6(unsigned int);

struct CComEnum {
    long __stdcall QueryInterface(void** ppv);
};

long __stdcall CComEnum::QueryInterface(void** ppv) {
    if (ppv == 0) {
        return 0x80004003;
    }
    *ppv = 0;
    void* mem = sub_62FEF6(0x1c);
    if (mem != 0) {
        *(int*)((char*)mem + 4) = 0;
        *(int*)((char*)mem + 0x10) = 0;
        *(int*)((char*)mem + 0xc) = 0;
        *(int*)((char*)mem + 8) = 0;
        *(int*)((char*)mem + 0x14) = 0;
        *(int*)((char*)mem + 0x18) = 0;
        *(int*)mem = 0x784fa8;
        int* p = *(int**)0x8bae44;
        int* vtbl = *(int**)p;
        void (*fn)(void*) = *(void (**)(void*))(vtbl + 1);
        fn((void*)mem);
    }
    *ppv = mem;
    return 0;
}
