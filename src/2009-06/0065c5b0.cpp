// from server: 100% by why2
struct PartInstance {
    char pad[0x118];
    void* field_118;
    void* get() const;
};

void* PartInstance::get() const {
    return (char*)(*(void**)((char*)field_118 + 0xe0)) + 4;
}
