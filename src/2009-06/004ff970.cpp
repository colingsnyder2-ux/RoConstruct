// from server: 100% by why2
extern "C" void __cdecl sub_718CDE(void*);

struct RakPeer {
    void* field0;
    int field4;
    unsigned int field8;
    void func();
};

void RakPeer::func() {
    if (field8 > 0) {
        sub_718CDE(field0);
    }
}
