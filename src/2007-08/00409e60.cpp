// from server: 100% by Yeetserama
// hypothesis: 00409e60 forwards QueryInterface through the contained object at 0x28.
struct Vtbl
{
    void* (__stdcall *queryInterface)(void* self, const void* guid, void** out);
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

extern "C" void* __stdcall forwardQueryInterface(Outer* self, const void* guid, void** out)
{
    Inner* inner = self->inner;
    return inner->vtbl->queryInterface(inner, guid, out);
}
