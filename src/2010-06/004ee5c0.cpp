// from server: 32% by atomic.potato
struct S {
    char pad0[0x24];
    float f24;
    float f28;
    float f2c;
    void copyFrom(void* src);
};

extern "C" void* __cdecl sub_4ed9e0(void*);

void S::copyFrom(void* src) {
    char* d = (char*)this;
    char* s = (char*)src;
    for (int i = 0; i < 9; ++i) {
        ((int*)d)[i] = ((int*)s)[i];
    }
}

S* __cdecl sub_4ee5c0(S* self, void* arg) {
    void* p = sub_4ed9e0(arg);
    self->copyFrom(p);
    self->f24 = *(float*)((char*)p + 0x24);
    self->f28 = *(float*)((char*)p + 0x28);
    self->f2c = *(float*)((char*)p + 0x2c);
    return self;
}
