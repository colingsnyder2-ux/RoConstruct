// from server: 70% by atomic.potato
struct Inner {
    char pad0[0xc];
    float (__thiscall *fn)(int);
};

struct Outer {
    char pad0[0x1c];
    Inner *inner;
};

struct Result {
    char pad0[4];
    int type;
    float value;
};

extern "C" void __stdcall sub_676F40(Result *r);

void __stdcall sub_644530(Outer *self, int arg)
{
    Inner *in = self->inner;
    float v = in->fn(arg);
    Result *r = (Result *)((char *)self + 0x10);
    sub_676F40(r);
    r->value = v;
    r->type = 7;
}
