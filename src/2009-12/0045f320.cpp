// from server: 69% by atomic.potato
struct ToggleIDEModeVerb {
    char pad[0x10];
    double field_0x10;
    bool f();
};

extern "C" void __fastcall sub_5eab80(void*);
extern "C" void* __cdecl sub_7f3b1e();
extern double dbl_9adf68;

bool ToggleIDEModeVerb::f() {
    sub_5eab80(this);
    double v = field_0x10 + dbl_9adf68;
    if (v > 0.0) {
        return false;
    }
    char* p = (char*)sub_7f3b1e();
    p = *(char**)(p + 4);
    p = *(char**)(p + 0x20);
    return p[0x109] == 0;
}
