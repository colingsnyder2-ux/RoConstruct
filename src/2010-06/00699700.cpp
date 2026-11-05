// from server: 55% by atomic.potato
struct EventDesc_00699700 {
    float m_x;
    float m_y;
    float m_z;
    float __cdecl f(float* p);
};

float EventDesc_00699700::f(float* p)
{
    float x = m_x - p[0];
    float y = m_y - p[1];
    float z = p[2];
    return (x * x + y * y) / z;
}
