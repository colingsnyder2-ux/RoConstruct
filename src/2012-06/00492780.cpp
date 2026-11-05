// from server: 69% by atomic.potato
struct ToggleIDEModeVerb {
    char pad[0x10];
    double field_0x10;
    bool f();
};

extern "C" void __cdecl sub_62B600();
extern "C" void* __cdecl sub_9823D2();
extern double dbl_B53B08;

bool ToggleIDEModeVerb::f() {
    sub_62B600();
    if (field_0x10 + dbl_B53B08 <= 0.0) {
        return false;
    }
    void* p = sub_9823D2();
    unsigned char* q = *(unsigned char**)((char*)p + 4);
    unsigned char* r = *(unsigned char**)((char*)q + 0x20);
    return r[0x111] == 0;
}
