// from server: 100% by king_originala
struct Worker {
    void clear();
};

struct Accessor {
    virtual void slot0();
    virtual Worker* get();
};

struct State {
    char padding[0xA8];
    int value;
};

struct RootInstance {
    char padding0[0x288];
    Accessor accessor;
    char padding1[0x58];
    State* state;
    char padding2[0xE8];
    bool flag;

    void reset();
};

void RootInstance::reset() {
    flag = false;
    accessor.get()->clear();
    state->value = 0;
}
