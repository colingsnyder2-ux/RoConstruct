// from server: 100% by atomic.potato
extern "C" void* __cdecl sub_7a79a0(unsigned int size);

struct G3D_VRay_holder {
    char pad0[8];
    float f8;
    float fC;
    float f10;
    float f14;
    float f18;
    float f1C;
    void* clone();
};

void* G3D_VRay_holder::clone() {
    G3D_VRay_holder* p = (G3D_VRay_holder*)sub_7a79a0(0x20);
    if (p) {
        p->f8 = f8;
        *(void**)p = (void*)0xa1b088;
        *(void**)((char*)p + 4) = (void*)0xa1ac90;
        p->fC = fC;
        p->f10 = f10;
        p->f14 = f14;
        p->f18 = f18;
        p->f1C = f1C;
        return p;
    }
    return 0;
}
