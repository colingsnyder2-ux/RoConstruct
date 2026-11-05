// from server: 100% by colin
struct RakPeer {
    unsigned int field_0;
    unsigned int field_4;
    unsigned int field_8;
    unsigned int field_c;
    void method();
};

extern "C" void __cdecl sub_62FC62(unsigned int);

void RakPeer::method() {
    if (field_c > 0) {
        sub_62FC62(field_0);
    }
}
