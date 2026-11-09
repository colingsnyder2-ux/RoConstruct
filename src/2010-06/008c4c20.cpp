// from server: 82% by atomic.potato
struct ViewRbxGfx
{
    char pad[4];
    void *value;
    void f();
    void g(void *);
};

extern "C" void *__cdecl get_value();

void ViewRbxGfx::f()
{
    void *p = value ? get_value() : 0;
    g(p);
}
