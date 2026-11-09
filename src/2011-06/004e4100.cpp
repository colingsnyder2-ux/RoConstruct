// from server: 100% by atomic.potato
extern "C" void __cdecl sub_80a058(void*);

struct RefPropDescriptor {
    void* vfptr;
    char pad[0x1c];
    void* field20;
    void* destroy(char flag);
};

void* RefPropDescriptor::destroy(char flag) {
    if (field20) {
        sub_80a058(field20);
    }
    vfptr = (void*)0xa5bee0;
    if (flag & 1) {
        sub_80a058(this);
    }
    return this;
}
