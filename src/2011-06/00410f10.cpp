// from server: 27% by atomic.potato
struct AuthoringSettings {
    char pad0[0x90];
};

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __stdcall sub_410060(void* p);
extern "C" void __stdcall sub_40f9b0(void* self, void* a, void* b);

struct Base {
    void ctor();
};

void AuthoringSettings_ctor(AuthoringSettings* self, void* arg);

void AuthoringSettings_ctor(AuthoringSettings* self, void* arg)
{
    void* mem = operator_new(0x90);
    void* obj = 0;
    if (mem) {
        sub_410060(mem);
        *(void**)((char*)mem + 0) = (void*)0xa5cd1c;
        *(void**)((char*)mem + 4) = (void*)0xa5cd14;
        *(void**)((char*)mem + 0x18) = (void*)0xa5cd08;
        *(void**)((char*)mem + 0x1c) = (void*)0xa5ccfc;
        obj = mem;
    } else {
        obj = 0;
    }
    sub_40f9b0(self, obj, arg);
}
