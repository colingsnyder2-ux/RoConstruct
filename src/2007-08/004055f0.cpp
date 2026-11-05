// from server: 30% by colin
extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);
extern "C" unsigned int __stdcall GetModuleFileNameA(void*, char*, unsigned int);
extern "C" int __stdcall lstrlenA(const char*);
extern "C" long __stdcall LoadTypeLib(const unsigned short*, void**);
extern "C" long __stdcall LoadRegTypeLib(const void*, unsigned short, unsigned short, unsigned long, void**);

extern "C" void __cdecl _free(void*);

struct CRegObject {
    void* field0;
    void* field4;
    unsigned short field8;
    unsigned short fieldA;
    void* fieldC;
    void* field10;
    void* field14;

    long Load(void* p);
};

long CRegObject::Load(void* p)
{
    if (fieldC != 0 && field14 != 0)
        return 0;

    void* cs = (void*)(*(char**)0x8bae44 + 0x10);
    EnterCriticalSection(cs);

    long hr = (long)0x80004005;

    if (fieldC == 0) {
        void* p4 = field4;
        if (*(unsigned int*)0x8bae48 == *(unsigned int*)p4 &&
            *(unsigned int*)0x8bae4c == *(unsigned int*)((char*)p4 + 4) &&
            *(unsigned int*)0x8bae50 == *(unsigned int*)((char*)p4 + 8) &&
            *(unsigned int*)0x8bae54 == *(unsigned int*)((char*)p4 + 0xc) &&
            field8 == 0xffff && fieldA == 0xffff)
        {
            char buf[0x104];
            unsigned int n = GetModuleFileNameA(*(void**)0x8c9828, buf, 0x104);
            if (n != 0 && n != 0x104) {
                void* hmod = (void*)(*(unsigned int(*)())0x8bab64)();
                int len = lstrlenA(buf);
                int total = len + 1;
                void* mem = 0;
                int r = 0;
                if (total <= 0x400) {
                    mem = (void*)0;
                }
                if (r >= 0) {
                    void* lib = 0;
                    if (LoadTypeLib((const unsigned short*)buf, &lib) >= 0) {
                        void* reg = 0;
                        if (lib != 0) {
                            void** vt = *(void***)lib;
                            void (__stdcall *rel)(void*) = (void (__stdcall *)(void*))vt[1];
                            rel(lib);
                        }
                        if (LoadRegTypeLib(*(const void**)lib, field8, fieldA, 0, &reg) >= 0) {
                            fieldC = reg;
                        }
                    }
                }
            }
        } else {
            void* lib = 0;
            if (LoadTypeLib((const unsigned short*)p, &lib) >= 0) {
                void* reg = 0;
                if (lib != 0) {
                    void** vt = *(void***)lib;
                    void (__stdcall *rel)(void*) = (void (__stdcall *)(void*))vt[1];
                    rel(lib);
                }
                if (LoadRegTypeLib(*(const void**)lib, field8, fieldA, 0, &reg) >= 0) {
                    fieldC = reg;
                }
            }
        }
    }

    if (fieldC != 0 && field14 == 0) {
        hr = 0;
    }

    LeaveCriticalSection(cs);
    return hr;
}
