// from server: 100% by king_originala
struct S {
    char padding0[0x150];
    unsigned int count;
    char padding1[0x11];
    bool enabled;

    void prepare(const char*);
    void step();
    void f();
};

void S::f()
{
    if (enabled) {
        prepare("base");
        while (count > 1)
            step();
    }
}
