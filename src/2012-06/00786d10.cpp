// from server: 37% by atomic.potato
struct Sub {
    char pad[0x84];
    void destroy();
};

struct S {
    char pad0[0x84];
    Sub sub;
    void cleanup();
    S();
    ~S();
};

void S::cleanup() {
    sub.destroy();
}

S::~S() {
    cleanup();
    *(void**)this = (void*)0xbb0964;
    *(void**)((char*)this + 4) = (void*)0xbb0958;
    *(void**)((char*)this + 0x18) = (void*)0xbb094c;
    *(void**)((char*)this + 0x1c) = (void*)0xbb0940;
    ((void (*)(void*))0x685090)(this);
}
