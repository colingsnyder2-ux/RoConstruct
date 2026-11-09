// from server: 100% by why2
struct PartInstance {
    char pad[0x118];
    void* ptr;
    float get() const;
};

float PartInstance::get() const {
    return *(float*)((char*)ptr + 0xf4);
}
