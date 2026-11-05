// from server: 27% by atomic.potato
struct GfxBinding
{
    virtual void f();
};

void GfxBinding::f()
{
    (*(void (__thiscall **)(GfxBinding *))(*(int **)this)) (this);
}
