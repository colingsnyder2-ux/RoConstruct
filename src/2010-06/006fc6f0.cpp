// from server: 66% by atomic.potato
struct GuiButton
{
    char padding[148];
    void* field_94;
    void f(float value);
};

extern "C" void G1_func_00702070(float);

void GuiButton::f(float value)
{
    G1_func_00702070(value);
}
