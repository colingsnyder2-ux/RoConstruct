// from server: 100% by king_originala
struct Target;

struct VTable {
    void* reserved[8];
    void (__thiscall* invoke)(Target*, float);
};

struct Target {
    VTable* vtable;
};

struct S {
    char reserved[0xec];
    int enabled;
    Target* target;
    void f(float value, int unused);
};

void S::f(float value, int unused) {
    if (enabled)
        target->vtable->invoke(target, value);
}
