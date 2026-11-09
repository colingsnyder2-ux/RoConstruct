// from server: 100% by tester
struct CXTColorBase {
    void f();
    char pad[0x54];
    char flag5c;
};

extern "C" void __fastcall sub_62fcd4(void* p);

void CXTColorBase::f() {
    sub_62fcd4(this);
    if (flag5c) {
        void** vt = *(void***)this;
        void (__fastcall *fn)(void*) = (void (__fastcall *)(void*))vt[0x150 / 4];
        fn(this);
    }
}
