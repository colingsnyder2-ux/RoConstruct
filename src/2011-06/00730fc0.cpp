// from server: 23% by atomic.potato
struct Inner {
    char pad[0x1c];
    int field_1c;
};

struct Outer {
    char pad0[0xbc];
    Inner inner;
};

extern "C" void __stdcall sub_730df0();
extern "C" void* __stdcall sub_a404c8(void*);

void __stdcall func_00730fc0(Outer* src, Outer* dst)
{
    sub_730df0();
    sub_a404c8(&src->inner);
    dst->inner.field_1c = src->inner.field_1c;
}
