// from server: 84% by colin
struct Inner {
    void* pad0;
    void* fn;
};

struct Mid {
    char pad[0x30];
    Inner* inner;
};

struct Outer {
    void invoke(Mid* p);
};

void Outer::invoke(Mid* p)
{
    Inner* i = p->inner;
    void* f = *(void**)i;
    typedef void (__stdcall *Fn)(Inner*);
    ((Fn)f)(i);
}
