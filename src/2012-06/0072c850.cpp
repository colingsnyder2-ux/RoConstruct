// from server: 35% by atomic.potato
// roc 2012-06 0072c850  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable
// Make this compile to the exact bytes below, then: roc check 2012-06 0072c850

extern "C" void* __cdecl sub_98211A(unsigned int);
extern "C" void __cdecl sub_982114(void*);
extern "C" void __cdecl sub_972290(unsigned char, const char*);
extern "C" void* __cdecl sub_72BE80(void*, void*, void*, void*, void*);
extern "C" void* __cdecl sub_7235F0(void*, void*);
extern "C" void __cdecl sub_40CF10(void*, void*);

extern unsigned char byte_E580B3;
extern void* dword_E5809C;
extern void* dword_B229EC;

struct VInstance {
    void construct(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i, void* j, void* k, void* l);
};

void VInstance::construct(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i, void* j, void* k, void* l)
{
    void* p1 = sub_72BE80(a, b, c, d, e);
    void* v = *(void**)p1;
    *(void**)p1 = 0;
    void* p2 = sub_7235F0(f, g);
    sub_40CF10(this, p2);
    sub_982114(h);
    *(void**)this = (void*)0xba6154;
    if (byte_E580B3) {
        if (!((bool (__stdcall*)(void*))dword_B229EC)((void*)0xdaf140)) {
            if (dword_E5809C) {
                if (((bool (__stdcall*)(int, const char*, const char*))dword_E5809C)(0xae, (const char*)0xb58618, (const char*)0xb44978))
                    goto done;
            }
            sub_972290(byte_E580B3, (const char*)0xb58680);
        }
    }
done:
    (void)v;
}
