// from server: 32% by atomic.potato
extern "C" void __stdcall Function_00411f60(float);

struct RBX_TextLabel {
    char pad0[560];
    float m_value;
    void f(float value);
};

void RBX_TextLabel::f(float value)
{
    if (m_value == value)
        return;

    m_value = value;
    Function_00411f60(value);
}
