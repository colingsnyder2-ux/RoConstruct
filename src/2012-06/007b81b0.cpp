// from server: 26% by atomic.potato
struct RBX_Sparkles_007b81b0 {
    char pad_0000[0x88];
    float m_x;
    float m_y;
    float m_z;
    void update(float x, float y, float z);
};

extern float g_007bb9cb8;
extern float g_007bb9cb4;
extern "C" void __stdcall sub_00414da0(const char*);

void RBX_Sparkles_007b81b0::update(float x, float y, float z)
{
    float nx = x * g_007bb9cb8;
    float ny = y * g_007bb9cb4;
    if (m_x != nx || m_y != ny || m_z != z)
    {
        m_x = nx;
        m_y = ny;
        m_z = z;
        sub_00414da0("?SparkleColor");
    }
}
