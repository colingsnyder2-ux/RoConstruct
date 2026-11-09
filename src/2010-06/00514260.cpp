// from server: 100% by atomic.potato
struct RakPeerInterface {
    bool f1(const void*);
    bool f2(const void*);
    int __cdecl f3(const void*);
};

int RakPeerInterface::f3(const void* p) {
    if (f1(p))
        return -1;
    return f2(p) ? 0 : 1;
}
