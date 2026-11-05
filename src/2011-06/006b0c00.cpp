// from server: 55% by atomic.potato
struct Inner {
    char pad[4];
    void init(int);
};

struct Outer {
    Inner inner;
    void* method(int, int);
};

extern "C" void __stdcall sub_004c1670(Inner*, int);
extern "C" void* __stdcall sub_006aff80(Outer*, int, int);

void* Outer::method(int a, int b)
{
    inner.init(0);
    sub_004c1670(&inner, 1);
    return sub_006aff80(this, a, b);
}
