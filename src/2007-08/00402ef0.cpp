// from server: 100% by Yeetserama
// hypothesis: 00402ef0 is a COM QueryInterface forwarding thunk; the only
// difference from exact 00412490 is the contained-object offset (0x30 vs 8).
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
    char pad[0x30];
    Inner* inner;
};

extern "C" void* __stdcall forwardQueryInterface(Outer* self, const void* guid, void** out)
{
    Inner* inner = self->inner;
    return inner->vtbl->queryInterface(inner, guid, out);
}
