// from server: 100% by tester
struct RakPeer {
    void clearIfEqual(void* p);
    char pad[0xa7c];
    void* field_0x72c;
};

void RakPeer::clearIfEqual(void* p) {
    if (field_0x72c == p) {
        field_0x72c = 0;
    }
}
