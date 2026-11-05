// from server: 100% by colin
struct RakPeer {
    void* ptr;
    unsigned int pad;
    unsigned int count;
    void clear();
};

extern "C" void __cdecl free_mem(void*);

void RakPeer::clear() {
    if (count > 0) {
        free_mem(ptr);
    }
}
