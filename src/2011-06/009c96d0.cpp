// from server: 27% by atomic.potato
struct GfxBinding
{
    virtual void f();
    void g();
};

void GfxBinding::g()
{
    f();
}
