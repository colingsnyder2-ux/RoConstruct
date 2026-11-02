// from server: 100% by Yeetserama
// hypothesis: 00402eb0 forwards AddRef through the contained object at 0x30.
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
    char pad[0x30];
    Inner* inner;
};

extern "C" unsigned long __stdcall forwardAddRef(Outer* self)
{
    Inner* inner = self->inner;
    return inner->vtbl->addRef(inner);
}
