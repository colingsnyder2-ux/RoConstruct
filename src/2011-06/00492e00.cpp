// from server: 84% by atomic.potato
struct Inner {
    char pad[0xc];
    void* field_c;
};

struct CSettingsPropGrid {
    void f(void* a, Inner* b);
};

extern "C" void* __stdcall sub_40e0a0();
extern "C" bool __stdcall sub_5e4200(void* ecx, void* arg);
extern "C" void __stdcall sub_44d150(void* ecx, void* a, void* b);

void CSettingsPropGrid::f(void* a, Inner* b) {
    void* r = sub_40e0a0();
    if (sub_5e4200(b->field_c, r)) {
        sub_44d150(this, a, b);
    }
}
