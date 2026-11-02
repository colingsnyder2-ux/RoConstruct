// from server: 100% by Yeetserama
// hypothesis: 00409e20 is a COM AddRef forwarding thunk; the only difference
// from exact 00412470 is the contained-object offset (0x28 vs 8).
struct Vtbl
{
    void* (__stdcall *queryInterface)(void* self);
    unsigned long (__stdcall *addRef)(void* self);
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

extern "C" unsigned long __stdcall forwardAddRef(Outer* self)
{
    Inner* inner = self->inner;
    return inner->vtbl->addRef(inner);
}
