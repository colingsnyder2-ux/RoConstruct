// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
namespace RBX {
class ICameraOwner {
public:
    virtual void f();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
};

class Camera {
public:
    void getAngles(float&, float&, float&);
    void setAngles(float, float, float);
    ICameraOwner* getCameraOwner();
    void update(float);
};
}

extern float __cdecl normalizeAngle(float);

void RBX::Camera::update(float delta)
{
    if (delta != 0.0f) {
        float a, b, c;
        getAngles(a, b, c);
        a = normalizeAngle(a + delta);
        setAngles(a, b, c);

        ICameraOwner* owner = getCameraOwner();
        if (owner)
            owner->slot3();
    }
}
