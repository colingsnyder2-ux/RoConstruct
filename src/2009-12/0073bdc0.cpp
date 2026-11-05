// from server: 88% by atomic.potato
struct S
{
    typedef float* (__thiscall *Getter)(void*);

    void* vtable;
    void* unknown;
    Getter get;
    void* context;

    float* f(float* out, void* value);
};

float* S::f(float* out, void* value)
{
    void* object = value ? (char*)value - 28 : 0;
    float* result = get(object);
    out[0] = result[0];
    out[1] = result[1];
    out[2] = result[2];
    return out;
}
