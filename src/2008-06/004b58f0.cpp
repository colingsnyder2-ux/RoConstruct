// from server: 100% by king_originala
extern "C" void __cdecl release(void *) throw();

struct Allocation {
    unsigned int reserved;
    void *pointer;
    ~Allocation();
};

struct OptionalAllocation {
    unsigned int owned;
    void *pointer;
    ~OptionalAllocation();
};

struct State {
    unsigned char storage[16];
    void clear();
};

struct S {
    Allocation allocation;
    unsigned int reserved;
    State state;
    OptionalAllocation optional;
    ~S();
};

inline Allocation::~Allocation() {
    release(pointer);
}

inline OptionalAllocation::~OptionalAllocation() {
    if (owned)
        release(pointer);
}

S::~S() {
    state.clear();
}
