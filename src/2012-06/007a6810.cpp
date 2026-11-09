// from server: 56% by atomic.potato
struct Inner {
    char pad0[0xc];
    int field_c;
};

struct Mid {
    char pad0[0x1c];
    Inner inner;
};

struct Outer {
    char pad0[0x38];
    Mid* ptr;
    void method();
};

struct Caller {
    char pad0[0];
    char method(int arg);
};

extern "C" int __cdecl sub_7825b0();
extern "C" void __cdecl sub_7a6c40();

void Outer::method()
{
    Mid* m = ptr;
    if (m == 0)
        return;
    Inner* in = &m->inner;
    if (in == 0)
        return;
    int v = in->field_c;
    int r = sub_7825b0();
    Caller* c = (Caller*)&v;
    if (c->method(r))
    {
        Mid* back = (Mid*)((char*)in - 0x1c);
        if (back != 0)
            sub_7a6c40();
    }
}
