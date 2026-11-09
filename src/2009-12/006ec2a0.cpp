// from server: 82% by atomic.potato
extern "C" void __stdcall G1_func_007e1de0(const char *);

struct S
{
    int f();
    char padding[0xf0];
    void *field_f0;
};

int S::f()
{
    if (field_f0 == 0)
        G1_func_007e1de0("Accessing Primitive::getPrimitiveType with NULL Geometry");

    struct VTable
    {
        int unused0;
        int unused1;
        int (*getType)();
    };

    VTable *v = *(VTable **)field_f0;
    return v->getType();
}
