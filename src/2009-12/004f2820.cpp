// from server: 27% by atomic.potato
struct GfxBinding
{
    virtual void f();
};

void GfxBinding::f()
{
    ((void (__thiscall **)(GfxBinding *))*(GfxBinding **)this)[0](this);
}
