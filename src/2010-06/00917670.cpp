// from server: 2% by atomic.potato
struct GfxAttachement {
    char pad[0xc0];
    int field;
    void* getSomething();
    void doSomething(int, int, int);
};

void* GfxAttachement::getSomething() {
    return 0;
}

void GfxAttachement::doSomething(int a, int b, int c) {
    void* p = this->getSomething();
    ((GfxAttachement*)p)->doSomething(a, b, c);
}
