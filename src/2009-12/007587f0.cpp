// from server: 75% by atomic.potato
extern "C" void __cdecl call_006b1430(float, float, float, int);

struct ImageLabel_007587f0 {
    char pad0[32];
    float m_x;
    float m_y;
    float m_z;
    int f(int value);
};

int ImageLabel_007587f0::f(int value)
{
    call_006b1430(m_x, m_y, m_z, value);
    return value;
}
