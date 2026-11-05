// from server: 34% by atomic.potato
extern "C" void* __cdecl sub_98211a(unsigned int);

struct RBX_VSelectionBox_FactoryProduct_Creator {
    void* __cdecl sub_7784e0(void* a, void* b);
};

struct Sub8e0e90 {
    void sub_8e0e90(int);
};

struct Sub778470 {
    void sub_778470(void*, void*);
};

void* RBX_VSelectionBox_FactoryProduct_Creator::sub_7784e0(void* a, void* b) {
    void* p = sub_98211a(0x428);
    void* q = 0;
    if (p) {
        ((Sub8e0e90*)p)->sub_8e0e90(1);
        q = p;
    }
    ((Sub778470*)this)->sub_778470(q, a);
    return this;
}
