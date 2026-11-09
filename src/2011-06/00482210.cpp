// from server: 69% by atomic.potato
struct ToggleIDEModeVerb {
    char pad0[0x10];
    double field10;
    bool method();
};

extern "C" void __stdcall sub_53F700();
extern "C" void* __stdcall sub_80A31C();
extern double dbl_A690F0;

bool ToggleIDEModeVerb::method() {
    sub_53F700();
    if (field10 + dbl_A690F0 > 0.0) {
        return false;
    }
    void* p = sub_80A31C();
    char* q = *(char**)((char*)p + 4);
    char* r = *(char**)(q + 0x20);
    return r[0x10d] == 0;
}
