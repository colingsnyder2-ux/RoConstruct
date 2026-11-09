// from server: 100% by Intel
extern "C" int dword_DB980C[];

struct VExplosion {
    struct EventDesc {
        static int func(int index);
    };
};

int VExplosion::EventDesc::func(int index) {
    return dword_DB980C[index];
}
