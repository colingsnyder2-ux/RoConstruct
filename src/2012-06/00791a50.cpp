// from server: 39% by atomic.potato
struct VMeshIdPropDesc {
    void* vtable;
    char pad[0x24];
    void init(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i, void* j);
};

extern "C" void* __cdecl sub_982114(void*);
extern "C" void* __cdecl sub_5cf230(void*, void*);
extern "C" void __cdecl sub_972290(unsigned char, void*);
extern "C" void* __cdecl sub_791520(void*, void*, void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_70c470(void*, void*);
extern "C" int __cdecl sub_b229ec(void*);

extern unsigned char byte_E580B3;
extern void* dword_E5809C;

void VMeshIdPropDesc::init(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i, void* j)
{
    void* tmp[3];
    void* r;
    void* p;
    void* q;

    r = sub_791520(&tmp, a, b, c, d, e, f);
    p = *(void**)r;
    *(void**)r = 0;
    tmp[0] = p;
    q = sub_5cf230(g, h);
    sub_70c470(this, q);
    sub_982114(i);
    this->vtable = (void*)0xbb2440;
    if (byte_E580B3 != 0) {
        if (sub_b229ec((void*)0xdc1ef8) == 0) {
            if (dword_E5809C != 0) {
                if (((int (__cdecl*)(int, void*, void*))dword_E5809C)(0xae, (void*)0xb58618, (void*)0xb44978) != 0)
                    return;
            }
            sub_972290(byte_E580B3, (void*)0xb58680);
        }
    }
}
