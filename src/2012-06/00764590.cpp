// from server: 100% by Intel
struct VExplosion {
    struct EventDesc {
        static void func();
    };
};

extern "C" char byte_E3745C;

void VExplosion::EventDesc::func() {
    byte_E3745C = 0;
}
