// from server: 100% by EspClaude
// roc 2007-08 004633f0  unit: CSettingsDialog
struct Vector2 {
    float x, y;
    Vector2() {}
    Vector2(float _x, float _y) : x(_x), y(_y) {}
    Vector2 operator+(const Vector2& v) const { return Vector2(x + v.x, y + v.y); }
    Vector2 operator*(double s) const { return Vector2(x * s, y * s); }
};
class CSettingsDialog {
    char pad[0x58];
    Vector2 m_a;
    Vector2 m_b;
    char pad2[8];
    Vector2 m_p;
public:
    bool check();
};
bool CSettingsDialog::check()
{
    Vector2 size = m_a + m_b;
    Vector2 half = size * 0.5;
    if (m_p.x < -half.x)
        return false;
    if (m_p.x > half.x)
        return false;
    if (m_p.y < -half.y)
        return false;
    if (m_p.y > half.y)
        return false;
    return true;
}
