// from server: 16% by atomic.potato
extern "C" void* __stdcall make_desc_005b5e60(const char*, int);
extern "C" void* __cdecl func_007a799a(unsigned int);
extern "C" void* __cdecl func_007a79a0(unsigned int);
extern "C" void __cdecl func_007a799a_free(void*);
extern "C" void __cdecl func_00443800(void*, void*);

struct SpawnerService {
    void construct(void* a, void* b, void* c, void* d, void* e, void* f);
};

void SpawnerService::construct(void* a, void* b, void* c, void* d, void* e, void* f) {
    void* desc = make_desc_005b5e60((const char*)a, (int)b);
    func_00443800(this, desc);
    void* obj = func_007a79a0(0x20);
    *(void**)this = (void*)0xa0acfc;
    if (obj) {
        *(void**)obj = (void*)0xa3b944;
        *(void**)((char*)obj + 4) = this;
        *(void**)((char*)obj + 8) = c;
        *(void**)((char*)obj + 0xc) = d;
        *(void**)((char*)obj + 0x10) = 0;
        *(void**)((char*)obj + 0x14) = 0;
        *(void**)((char*)obj + 0x18) = 0;
    }
    void* old = *(void**)((char*)this + 0x1c);
    if (obj != old) {
        if (old) func_007a799a_free(old);
    }
    *(void**)((char*)this + 0x1c) = obj;
}
