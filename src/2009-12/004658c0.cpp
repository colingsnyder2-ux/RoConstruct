// from server: 36% by atomic.potato
extern "C" void* __cdecl sub_7F3860(unsigned int);
extern "C" void __cdecl sub_6DFA90(void*);

struct RBX_VExtrudedPartInstance_FactoryProduct_Creator {
    void* __cdecl sub_4658C0(void* a);
    void sub_465810(void* p, void* a);
};

void* RBX_VExtrudedPartInstance_FactoryProduct_Creator::sub_4658C0(void* a) {
    void* p = sub_7F3860(0x100);
    if (p) {
        sub_6DFA90(p);
    } else {
        p = 0;
    }
    sub_465810(p, a);
    return this;
}
