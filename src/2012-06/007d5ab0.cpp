// from server: 51% by atomic.potato
struct PropBase {
    char pad0[0x28];
    void* field28;
};

struct PropDesc {
    char pad0[0x18];
};

extern "C" void __cdecl sub_00982114(void*);
extern "C" void* __cdecl sub_0098211a(unsigned int);
extern "C" void __cdecl sub_00972290(unsigned char, const char*);
extern "C" void* __cdecl sub_00782e30(void*, void*, void*);
extern "C" void __cdecl sub_00736610(void*, void*);

extern unsigned char g_e580b3;
extern void* g_e5809c;
extern void* g_b229ec;
extern const char g_b43f40[];
extern const char g_b44978[];
extern const char g_b932b8[];
extern void* g_dc07e8;

struct VRbxRayProp : PropBase {
    void construct(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i);
};

void VRbxRayProp::construct(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i)
{
    void* local0 = 0;
    void* local1 = 0;
    void* local2 = 0;
    void* local3 = 0;
    void* local4 = 0;

    local0 = a;
    local1 = b;
    local2 = c;
    local3 = d;
    local4 = e;

    void* r = sub_00782e30(f, g, h);
    sub_00736610(this, r);

    sub_00982114(0);

    *(void**)this = (void*)0xbb6bd0;

    if (g_e580b3) {
        if (!((bool (__thiscall*)(void*))g_b229ec)(&g_dc07e8)) {
            if (g_e5809c) {
                if (((bool (__cdecl*)(int, const char*, const char*))g_e5809c)(0x1a7, g_b43f40, g_b44978)) {
                    goto skip;
                }
            }
            sub_00972290(g_e580b3, g_b932b8);
        }
    }
skip:
    {
        PropDesc* p = (PropDesc*)sub_0098211a(0x18);
        if (p) {
            *(void**)p = (void*)0xbc0ca0;
            *(void**)((char*)p + 4) = this;
            *(void**)((char*)p + 8) = local0;
            *(void**)((char*)p + 0x10) = local1;
            *(void**)((char*)p + 0x14) = local2;
        }
        void* old = this->field28;
        if (p != old) {
            sub_00982114(old);
        }
        this->field28 = p;
    }
}
