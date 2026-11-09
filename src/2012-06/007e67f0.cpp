// from server: 46% by atomic.potato
extern "C" void __stdcall sub_414da0(void* p);
extern "C" char g_e4e9f8;

struct VScreenGui {
    char pad[0xa4];
    float m_x;
    float m_y;
    bool Update(float* v);
};

bool VScreenGui::Update(float* v)
{
    if (m_x == v[0] && m_y == v[1])
        return false;
    m_x = v[0];
    m_y = v[1];
    sub_414da0(&g_e4e9f8);
    return true;
}
