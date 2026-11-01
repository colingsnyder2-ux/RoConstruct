// from server: 100% by king_originala
struct Interface {
    virtual void unused();
    virtual char* get();
};

struct S {
    char padding[0x134];
    int* offsets;
    char* f();
};

char* S::f()
{
    Interface* base = reinterpret_cast<Interface*>(
        reinterpret_cast<char*>(this) + 0x134 + offsets[1]);
    char* result = base->get();
    return result ? result + 0x228 : 0;
}
