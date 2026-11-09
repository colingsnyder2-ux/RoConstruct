// from server: 16% by atomic.potato
extern "C" bool __cdecl sub_6f1db0(unsigned int);

struct RBX_GfxBinding {
    virtual void vfunc0();
    void sub_4f2840(unsigned int id);
};

void RBX_GfxBinding::sub_4f2840(unsigned int id) {
    if (id == 0xb9282c) {
        vfunc0();
        return;
    }
    if (id == 0xb927c8 || id == 0xb92890) {
        vfunc0();
        return;
    }
    if (id == 0xb928d0) {
        vfunc0();
        return;
    }
    if (id == 0xb927a8) {
        vfunc0();
        return;
    }
    if (id == 0xb94260) {
        vfunc0();
        return;
    }
    if (id == 0xb93394) {
        vfunc0();
        return;
    }
    if (sub_6f1db0(id)) {
        vfunc0();
        return;
    }
    if (id == 0xb92788) {
        vfunc0();
        return;
    }
}
