// from server: 100% by colin
struct ICameraSubject {
    void* field_0;
    void* field_4;
    void* Method(int);
};

void* ICameraSubject::Method(int arg) {
    void* self = this;
    void* p = field_4;
    *(void**)self = (void*)0x7a4cac;
    void* q = *(void**)((char*)p + 4);
    *(void**)((char*)q + (int)self + 4) = (void*)0x7a4ca4;
    if (arg & 1) {
        extern void __cdecl sub_62FC62(void*);
        sub_62FC62(self);
    }
    return self;
}
