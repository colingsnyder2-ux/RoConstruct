// from server: 45% by atomic.potato
extern "C" void __stdcall Function_00414da0(void);

struct RBX_GuiTextButton {
    char pad0[836];
    float m_value;
    void f(float value);
};

void RBX_GuiTextButton::f(float value)
{
    if (m_value <= value)
        return;
    m_value = value;
    Function_00414da0();
}
