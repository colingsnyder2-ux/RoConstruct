// from server: 100% by tester
struct RBX_Assembly {
    char pad[0x28];
    void* field_24;
    void* get();
};

void* RBX_Assembly::get() {
    char* p = (char*)field_24;
    char* q = *(char**)(p + 0x20);
    if (q != 0) {
        return q - 8;
    }
    return 0;
}
