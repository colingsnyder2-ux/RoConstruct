// from server: 60% by Intel
struct VExplosion {
    struct EventDesc {
        void __thiscall func(int arg);
    };
};

extern "C" void __stdcall std_basic_string_destructor(void*);

void VExplosion::EventDesc::func(int arg) {
    std_basic_string_destructor(reinterpret_cast<void*>(&arg));
}
