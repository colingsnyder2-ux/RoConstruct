// from server: 100% by Yeetserama
// hypothesis: 00409e40 forwards Release through the contained object at 0x28.
struct Vtbl
{
    void* (__stdcall *queryInterface)(void* self);
    unsigned long (__stdcall *addRef)(void* self);
    unsigned long (__stdcall *release)(void* self);
};

struct Inner
{
    Vtbl* vtbl;
};

struct Outer
{
    char pad[0x28];
    Inner* inner;
};

extern "C" unsigned long __stdcall forwardRelease(Outer* self)
{
    Inner* inner = self->inner;
    return inner->vtbl->release(inner);
}
