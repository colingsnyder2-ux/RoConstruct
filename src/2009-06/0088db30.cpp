// from server: 100% by tester
extern "C" void __cdecl sub_00645F10();
extern "C" void __cdecl sub_00719AFB(void*);

struct seg_00880000 {
    void func();
};

void seg_00880000::func() {
    sub_00645F10();
    sub_00719AFB((void*)0x0089A130);
}
