// from server: 62% by atomic.potato
struct RakPeer {
    char pad[0xb70];
    void sub_5673C0(void*, int);
    void sub_5672E0(void*);
    void func(char*, char);
};

void RakPeer::func(char* a, char b) {
    if (a == 0) return;
    char* p = (char*)this + 0xb70;
    if (b != 0) {
        sub_5673C0(&a, 0);
    } else {
        sub_5672E0(&a);
    }
}
