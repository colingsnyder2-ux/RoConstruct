// from server: 100% by why2
struct PartInstance {
    char pad[0x118];
    void* field_118;
    float get() const;
};

float PartInstance::get() const {
    return *(float*)((char*)field_118 + 0xf8);
}
