// from server: 37% by atomic.potato
struct Inner {
    char pad0[8];
    char field8;
    char pad9[0x10 - 9];
    char field18;
};

struct Outer {
    char pad0[5];
    char field5;
    char pad6[2];
    Inner inner;
};

extern "C" void __stdcall sub_795550(void*);
extern "C" void __stdcall sub_7955c0(void*);
extern "C" void __stdcall sub_6cbc60(void*, int, float, float);

void __cdecl sub_6cbf00(Outer* self, int a, float b, float c)
{
    char local[8];
    sub_795550(local);
    if (self->field5) {
        sub_6cbc60(&self->inner.field18, a, b, c);
    }
    sub_7955c0(local);
}
