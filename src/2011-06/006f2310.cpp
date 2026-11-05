// from server: 25% by atomic.potato
extern "C" int __stdcall sub_5E6770(int);
extern "C" void __stdcall sub_40A950(void*);
extern "C" void __stdcall sub_80B0AC(void*, void*);
extern "C" void* __stdcall sub_A404C4(const char*);

struct S {
    void f();
};

void S::f() {
    if (sub_5E6770(0) == 0) {
        char buf[0x44];
        void* p = sub_A404C4("The service is not installed");
        *(int*)(buf + 0x4C) = 0;
        sub_40A950(buf + 0x1C);
        sub_80B0AC(buf + 0x1C, (void*)0xB89120);
    }
}
