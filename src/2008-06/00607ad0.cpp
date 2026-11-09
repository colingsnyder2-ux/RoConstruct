// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
typedef float (__thiscall *FloatCallback)(void *);

struct Body {
    char pad0[0xB0];
    float value0;
    float value1;
    char pad1[0x34];
    float cached;
    bool dirty;
    char pad2[3];
    void *context;
    FloatCallback callback;

    float getCached();
};

inline float Body::getCached()
{
    if (dirty) {
        cached = callback(context);
        dirty = false;
    }
    return cached;
}

inline const float &minimum(const float &a, const float &b)
{
    return a < b ? a : b;
}

extern "C" float __cdecl transform(float);

struct Contact {
    char pad0[0x0C];
    Body *first;
    Body *second;
    char pad1[0x14];
    float coefficient;
    float transformed;
    float limit;

    void update();
};

void Contact::update()
{
    Body *a = second;
    Body *b = first;

    float x = a->value0;
    float y = b->value0;
    limit = minimum(x, y);

    float u = a->value1;
    float v = b->value1;
    float selected = minimum(u, v);

    float p = a->getCached();
    float q = b->getCached();
    coefficient = minimum(p, q);

    transformed = transform(selected) * coefficient;
}
