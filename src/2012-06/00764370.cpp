// from server: 28% by 41k
struct VExplosion {
    struct EventDesc {
        static void func();
    };
};

extern "C" void __stdcall func1(void*);
extern "C" void __stdcall func2(void*);

void VExplosion::EventDesc::func() {
    char padding[48];
    func1(padding);
    func2(padding);
}
