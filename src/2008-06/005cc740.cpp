// from server: 100% by Espeon
// from server: 82% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern float g83a3e8;

namespace RBX {
struct ICameraOwner {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void f();
};

struct Camera {
    ICameraOwner* getCameraOwner();
    void getAngles(float&, float&, float&);
    void setAngles(float, float, float);
    bool adjust(float);
};
}

bool RBX::Camera::adjust(float delta) {
    if (delta == 0.0f)
        return false;

    float x, y, z;
    getAngles(x, y, z);

    static float limit = g83a3e8;
    double value = (double)delta + y;
    value = -(double)limit >= value ? -(double)limit :
        (value >= (double)limit ? (double)limit : value);

    if (value != y) {
        setAngles(x, (float)value, z);
        ICameraOwner* owner = getCameraOwner();
        if (owner)
            owner->f();
        return true;
    }
    return false;
}
