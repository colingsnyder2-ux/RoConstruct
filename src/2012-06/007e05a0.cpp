// from server: 28% by atomic.potato
struct Inner {
    char pad0[0x10c];
    void* field_10c;
    char pad110[0x4];
    void* field_114;
};

extern "C" void __stdcall CloseHandle(void*);
extern "C" void __stdcall sub_7df500();
extern "C" void __stdcall sub_8bb7f0();

struct S {
    char pad0[0x10c];
    void* field_10c;
    char pad110[0x4];
    void* field_114;
    void method();
};

void S::method() {
    field_114 = (void*)0xbc1220;
    sub_7df500();
    void* old = field_10c;
    field_10c = 0;
    if (old) CloseHandle(old);
    sub_8bb7f0();
}
