// from server: 100% by why2
struct RakPeer {
    char pad[4];
    char flag;
    char pad2[0xb15 - 5];
    char field_b15;
    char f();
};

char RakPeer::f() {
    char al = flag;
    if (al != 0) {
        field_b15 = 0;
    }
    return al;
}
