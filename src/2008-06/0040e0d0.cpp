// from server: 100% by tester
struct CBrowserView {
    char pad[0x2c8];
    unsigned char field_2b4;
    void invoke(void* arg);
};

void CBrowserView::invoke(void* arg) {
    unsigned char value = field_2b4;
    void** vtbl = *(void***)arg;
    void (__thiscall *fn)(void*, unsigned int) = (void (__thiscall *)(void*, unsigned int))vtbl[0];
    fn(arg, value);
}