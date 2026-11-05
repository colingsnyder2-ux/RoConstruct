// from server: 100% by tester
struct PartInstance {
    char pad[0x168];
    void* ptr;
    float get() const;
};

float PartInstance::get() const {
    char* p = *(char**)((char*)this + 0x168);
    char* q = *(char**)(p + 0xf4);
    return *(float*)(q + 0x94);
}
