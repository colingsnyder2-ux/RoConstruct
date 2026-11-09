// from server: 100% by colin
struct RBX_Instance {
    static const char* className();
};

struct RBX_ServiceProvider {
    static const char* className();
};

struct RBX_Instance_Base {
    void* vftable;
};

struct RBX_Instance_Impl {
    char pad[0xbc];
    RBX_Instance_Impl* next;
};

extern "C" void* __cdecl sub_630D36(void* p, void* a, void* b, void* c, void* d);

struct RBX_Instance_Helper {
    void* findChild(void* p);
};

void* __fastcall sub_48E1C0(void* p);

void* __cdecl sub_48EE30(RBX_Instance_Impl* p)
{
    while (p) {
        void* r = sub_630D36(p, 0, (void*)0x881f4c, (void*)0x884e04, 0);
        if (r) {
            return sub_48E1C0(r);
        }
        p = p->next;
    }
    return 0;
}
