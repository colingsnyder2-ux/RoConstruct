// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
namespace RBX {
class Camera {
public:
    void getAngles(float&, float&, float&);
    void setAngles(float, float, float);
    void update(float);
};
}

extern float __cdecl normalizeAngle(double);

void RBX::Camera::update(float delta)
{
    if (delta != 0.0f) {
        float a, b, c;
        getAngles(a, b, c);
        a = normalizeAngle(a + delta);
        setAngles(a, b, c);
    }
}
