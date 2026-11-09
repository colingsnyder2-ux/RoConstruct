// from server: 100% by why2
struct Script {
    char pad[8];
    void* field8;
    void destroy();
};

void Script::destroy() {
    void* p = field8;
    if (p != 0) {
        void** vtbl = *(void***)p;
        void (__thiscall *fn)(void*, int) = (void (__thiscall *)(void*, int))vtbl[0];
        fn(p, 1);
    }
}
