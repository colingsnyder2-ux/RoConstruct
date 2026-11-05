// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
typedef float (__thiscall *Getter)(void *);

struct CachedFloat {
    float value;
    unsigned char dirty;
    unsigned char padding[3];
    void *object;
    Getter getter;

    float get();
};

struct Node {
    unsigned char padding[0xEC];
    CachedFloat cached;
};

struct S {
    unsigned char padding[12];
    Node *left;
    Node *right;

    float f();
};

inline float CachedFloat::get()
{
    if (dirty) {
        value = getter(object);
        dirty = 0;
    }
    return value;
}

inline const float &minimum(const float &a, const float &b)
{
    return b < a ? b : a;
}

float S::f()
{
    float a = right->cached.get();
    float b = left->cached.get();
    return minimum(b, a);
}
