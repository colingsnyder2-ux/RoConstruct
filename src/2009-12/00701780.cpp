// from server: 57% by atomic.potato
extern "C" int __stdcall sub_773730(int, int);

struct Assembly {
    char pad[0x24];
    void* field_24;
    bool f();
};

bool Assembly::f() {
    void* p = *(void**)((char*)field_24 + 0x1c);
    if (p) {
        return sub_773730((int)p - 8, 0) != 0;
    }
    return sub_773730(0, 0) != 0;
}
