// from server: 46% by atomic.potato
struct GuiTextButton_00739040
{
    char pad0[0x354];
    float value;
    void f(float);
};

extern "C" void __stdcall Function_00414da0(unsigned int);

void GuiTextButton_00739040::f(float value0)
{
    if (value0 <= value)
        return;
    value = value0;
    Function_00414da0(0xE34684);
}
