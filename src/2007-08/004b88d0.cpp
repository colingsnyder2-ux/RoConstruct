// from server: 100% by colin
struct RakPeer {
    char pad0[4];
    char field4;
    char pad5[0x895 - 5];
    char field895;
    char get();
};

char RakPeer::get() {
    char result = field4;
    if (result != 0) {
        field895 = 0;
    }
    return result;
}
