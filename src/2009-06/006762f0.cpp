// from server: 100% by why2
struct RBX_Assembly {
    char pad[0x24];
    void* field_24;
    void* get();
};

void* RBX_Assembly::get() {
    char* p = (char*)field_24;
    char* q = *(char**)(p + 0x1c);
    if (q != 0) {
        return q - 8;
    }
    return 0;
}
