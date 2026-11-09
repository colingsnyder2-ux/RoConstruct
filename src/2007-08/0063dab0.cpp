// from server: 56% by colin
// roc 2007-08 0063dab0  unit: CXTPPaintManager  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0063dab0

extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char*);
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void*, const char*);

extern "C" void* __cdecl sub_62fef6(unsigned int);
extern "C" void* __cdecl sub_64c800();
extern "C" void* __cdecl sub_6b3b00();

struct CXTPPaintManager {
    char pad[0xd0];
    void* field_0xd0;
    void* field_0xd4;
    void* sub_63dab0();
};

void* CXTPPaintManager::sub_63dab0() {
    void* p;
    sub_64c800();
    p = sub_62fef6(0x2c);
    if (p == 0) {
        sub_6b3b00();
    } else {
        p = 0;
    }
    field_0xd0 = p;
    field_0xd4 = 0;
    void* h = GetModuleHandleA("USER32");
    if (h != 0) {
        field_0xd4 = GetProcAddress(h, "SetLayeredWindowAttributes");
    }
    return this;
}
