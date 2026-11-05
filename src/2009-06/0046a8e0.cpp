// from server: 100% by tester
struct G3D_Shader
{
    static float* GetValue();
};

struct DxUserInput
{
    char pad0[88];
    float m_x;
    float m_y;
    void f();
};

void DxUserInput::f()
{
    float* p = G3D_Shader::GetValue();
    m_x = p[0];
    m_y = p[1];
}
