// from server: 72% by atomic.potato
struct S {
    void* p0;
    char pad[0x1c];
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    S* copy_from(S* other);
};

S* S::copy_from(S* other) {
    p0 = 0;
    if (other->p0) {
        p0 = other->p0;
        void** vt = *(void***)other->p0;
        void (*fn)(void*, void*, int) = (void (*)(void*, void*, int))vt[0];
        fn(other->p0, (char*)this + 8, 0);
    }
    f20 = other->f20;
    f24 = other->f24;
    f28 = other->f28;
    f2c = other->f2c;
    f30 = other->f30;
    return this;
}
