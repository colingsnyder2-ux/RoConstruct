// from server: 34% by atomic.potato
extern "C" void ViewRbxGfx_00575380(void *);

struct S
{
    void f(void *);
};

void S::f(void *arg)
{
    ViewRbxGfx_00575380((char *)this + 8);
}
