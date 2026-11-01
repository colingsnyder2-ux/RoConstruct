// from server: 100% by atomic.potato
struct Base {
    void init(void* p);
};

struct S : Base {
    char pad[0x78];
    int m78;
    int m7c;
    S* ctor(void* p);
};

S* S::ctor(void* p) {
    init(p);
    *(void**)this = (void*)0xa7fee0;
    m78 = *(int*)((char*)p + 0x78);
    m7c = *(int*)((char*)p + 0x7c);
    return this;
}
