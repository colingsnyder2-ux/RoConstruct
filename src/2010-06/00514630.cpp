// from server: 100% by atomic.potato
struct RakPeer {
    char pad[0xa40];
    int field_a40;
    void sub_51ef20(const char*);

    void sub_514630(const char* s);
};

void RakPeer::sub_514630(const char* s) {
    if (s != 0 && *s != 0) {
        ((RakPeer*)((char*)this + 0xa40))->sub_51ef20(s);
    }
}
