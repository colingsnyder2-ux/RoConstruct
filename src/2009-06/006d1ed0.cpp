// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    static const Vector3& unitY();
};
}
namespace RBX {
extern const G3D::Vector3 exeDefaultVector;
class Vector3ERA {
public:
    float alpha;
    G3D::Vector3 value;
    Vector3ERA(float a = 1.0f) : alpha(a) { reset(); }
    void reset();
};
class FloatERA {
public:
    float alpha;
    float value;
    FloatERA(float a = 1.0f) : alpha(a) { reset(); }
    void reset();
};
class VBase { };
class __declspec(novtable) Controller : public virtual VBase {
public:
    Controller();
    virtual void step();
    bool flag0;
    int unk;
    float maxValue;
    Vector3ERA era0;
    Vector3ERA era1;
    G3D::Vector3 target;
    FloatERA era2;
    bool flag1;
    G3D::Vector3 velocity;
    bool flag2;
};
Controller::Controller()
    : flag0(false), maxValue(10.0f), target(exeDefaultVector), flag1(false), velocity(0, 0, 0), flag2(false)
{
}
}
