// from server: 100% by atomic.potato
struct ViewRbxGfx
{
    char pad[36];
    void f(bool value);
};

void ViewRbxGfx::f(bool value)
{
    pad[20] = 0;
    if (value)
        pad[36] = 0;
}
