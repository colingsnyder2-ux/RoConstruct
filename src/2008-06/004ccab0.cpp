// from server: 100% by king_originala
extern "C" void __cdecl release(void *);

struct Allocation {
    unsigned int reserved0;
    void *pointer;
    unsigned int reserved1;

    ~Allocation() { release(pointer); }
};

struct ConditionalAllocation {
    unsigned int owned;
    void *pointer;

    ~ConditionalAllocation() {
        if (owned)
            release(pointer);
    }
};

struct Helper {
    unsigned char storage[16];
    void cleanup();
};

struct S {
    Allocation allocation;
    Helper helper;
    ConditionalAllocation conditional;

    ~S();
};

S::~S() {
    helper.cleanup();
}
