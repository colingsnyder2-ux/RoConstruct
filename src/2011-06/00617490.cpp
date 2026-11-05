// from server: 66% by atomic.potato
struct RBX_RootInstance;

extern "C" void __stdcall sub_48D4D0();
extern "C" void __stdcall sub_4B17F0();
extern "C" void __stdcall sub_6427C0();
extern "C" void* __stdcall sub_80B2EA(void*, void*, void*, void*, void*);

struct RBX_RootInstance {
    char pad[0x44];
    RBX_RootInstance* field_44;
    void func(int);
};

void RBX_RootInstance::func(int) {
    RBX_RootInstance* p = this;
    if (p == 0) return;
    RBX_RootInstance* a = p->field_44;
    if (a != 0) {
        RBX_RootInstance* b = a->field_44;
        if (b != 0) {
            sub_48D4D0();
        } else {
            a = b;
        }
    } else {
        a = p;
    }
    if (a == 0) return;
    void* r = sub_80B2EA(a, (void*)0xc071f8, (void*)0xc0c3e0, 0, 0);
    if (r == 0) return;
    sub_4B17F0();
    sub_6427C0();
}
