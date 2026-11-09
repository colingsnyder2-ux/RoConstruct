// from server: 46% by atomic.potato





struct Inner {
    char pad0[0x2c];
    void* field2c;
    char pad30[0xc];
    void* field3c;
};

struct ProfiledRakPeer {
    char pad0[0x2c];
    Inner inner;
    void method(void* arg);
};

extern "C" void __stdcall sub_52d8d0();
extern "C" void __stdcall sub_521910();
extern "C" void __stdcall sub_4159a0();

void ProfiledRakPeer::method(void* arg) {
    sub_52d8d0();
    sub_521910();
    sub_4159a0();
}
