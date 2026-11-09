// from server: 53% by atomic.potato
struct GuiRoot
{
    void f(float *value);
};

extern const float g_0;
extern const float g_1;

void GuiRoot::f(float *value)
{
    value[0] = g_0;
    value[1] = g_1;
}
