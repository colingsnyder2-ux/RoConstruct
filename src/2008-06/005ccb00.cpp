// from server: 100% by atomic.potato
extern "C" void* __cdecl sub_6A17C6(void*, void*, void*, void*, void*);

struct P8Camera_GetSetImpl {
    char pad[0x1dc];
    void* field_1dc;
    char get();
};

char P8Camera_GetSetImpl::get() {
    void* p = this->field_1dc;
    if (p) {
        p = sub_6A17C6(p, 0, (void*)0x92907c, (void*)0x948304, 0);
    } else {
        p = 0;
    }
    p = sub_6A17C6(p, 0, (void*)0x9516c8, (void*)0x948304, 0);
    if (p) {
        return *(char*)((char*)p + 0x3c);
    }
    return 0;
}
