// from server: 31% by atomic.potato
struct GfxBinding
{
    int f();
};

int GfxBinding::f()
{
    int (**vtable)(GfxBinding *);
    vtable = (int (**)(GfxBinding *))this;
    return vtable[0](this);
}
