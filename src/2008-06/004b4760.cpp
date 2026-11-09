// from server: 59% by king_originala
struct Object;

struct VTable {
    void (__thiscall *destroy)(Object *, unsigned int);
    void *reserved[57];
    void (__thiscall *invoke)(Object *, int);
};

struct Object {
    VTable *vtable;
};

struct Cleanup {
    Object *object;
    ~Cleanup();
};

Cleanup::~Cleanup()
{
    if (object != 0)
        object->vtable->destroy(object, 1);
}

struct S {
    unsigned char reserved[0x140];
    Object *object;

    S *__cdecl f(Object *replacement, int argument);
};

S *__cdecl S::f(Object *replacement, int argument)
{
    Cleanup cleanup;
    cleanup.object = replacement;

    Object *old = object;
    object = cleanup.object;
    cleanup.object = 0;

    if (old != 0)
        old->vtable->destroy(old, 1);

    object->vtable->invoke(object, argument);
    return this;
}
