// from server: 27% by atomic.potato
extern "C" void* __cdecl sub_7F3860(unsigned int);

struct C681DB0 {
    void sub_681DB0();
};

struct C414BD0 {
    void sub_414BD0(void*, int);
};

struct RBX_VModelInstance_FactoryProduct_Creator {
    void* __cdecl sub_414C80(void* a2);
};

void* RBX_VModelInstance_FactoryProduct_Creator::sub_414C80(void* a2) {
    void* p = sub_7F3860(0xF8);
    if (p) {
        ((C681DB0*)p)->sub_681DB0();
    } else {
        p = 0;
    }
    ((C414BD0*)a2)->sub_414BD0(p, 0);
    return a2;
}
