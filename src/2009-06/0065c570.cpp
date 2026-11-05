// from server: 100% by why2
struct PartInstance {
    char pad[0x118];
    void* ptr;
    float get() const;
};

float PartInstance::get() const {
    char* p = *(char**)((char*)this + 0x118);
    char* q = *(char**)(p + 0xe4);
    return *(float*)(q + 0x94);
}
