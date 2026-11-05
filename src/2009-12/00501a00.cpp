// from server: 27% by atomic.potato
extern "C" void* __cdecl sub_7F3860(unsigned int);

struct Sub6FD510 {
    void sub_6FD510();
};

struct Sub501950 {
    void sub_501950(void*, void*);
};

struct RBX_VSpawnLocation_FactoryProduct_Creator {
    void* __cdecl sub_501A00(void* a2);
};

void* RBX_VSpawnLocation_FactoryProduct_Creator::sub_501A00(void* a2) {
    void* v3 = 0;
    unsigned char flag = 0;
    void* v4 = sub_7F3860(0xb4);
    void* v5 = 0;
    if (v4) {
        ((Sub6FD510*)v4)->sub_6FD510();
        v5 = v4;
    } else {
        v5 = 0;
    }
    ((Sub501950*)a2)->sub_501950(v5, v3);
    return a2;
}
