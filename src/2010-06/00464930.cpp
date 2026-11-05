// from server: 69% by atomic.potato
struct ToggleIDEModeVerb {
    char pad0[0x10];
    double field10;
    bool method();
};

extern "C" void __cdecl sub_54E160();
extern "C" void* __cdecl sub_7A7C5E();
extern double g_A0EE78;

bool ToggleIDEModeVerb::method() {
    sub_54E160();
    double v = field10 + g_A0EE78;
    if (v > 0.0) {
        return false;
    }
    char* p = (char*)sub_7A7C5E();
    p = *(char**)(p + 4);
    p = *(char**)(p + 0x20);
    return p[0x109] == 0;
}
