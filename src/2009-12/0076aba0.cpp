// from server: 29% by atomic.potato
struct Inner {
    char pad0[4];
    char pad1[0x20];
    char field24;
};

struct Outer {
    char pad0[4];
    Inner inner;
    void method(Inner* src, char flag);
};

extern "C" void __stdcall sub_768540(Inner* dst, Inner* src);
extern "C" void __stdcall sub_768430(Inner* p);
extern "C" void __stdcall sub_76a6a0(Outer* self);

void Outer::method(Inner* src, char flag)
{
    Inner tmp;
    sub_768540(&tmp, src);
    tmp.field24 = flag;
    sub_76a6a0(this);
    sub_768430(&tmp);
}
