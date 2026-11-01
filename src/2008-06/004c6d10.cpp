// from server: 100% by colin
struct ProfiledRakPeer {
    int field0;
    int field4;
    int field8;
    void method();
};

extern "C" void __cdecl sub_6a067a(int);

void ProfiledRakPeer::method() {
    if (field4 != 0) {
        sub_6a067a(field8);
    }
}
