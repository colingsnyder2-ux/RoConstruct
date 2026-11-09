// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 { public: float x, y, z; Vector3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {} };
class CoordinateFrame { public: CoordinateFrame(); char data[0x30]; };
}
namespace RBX {
extern char sBodyGyro[];
struct B0 { virtual void f0(); char p[0x10]; };
struct B1 { virtual void f1(); };
struct B2 { virtual void f2(); int x; };
struct B3 { virtual void f3(); char p[0x68]; };
struct B4 { virtual void f4(); char p[0x1c]; };
struct B5 { virtual void f5(); char p[0x74]; };
struct B6 { virtual void f6(); char p[0x28]; };
class BodyMoverBase : public B0, public B1, public B2, public B3, public B4, public B5, public B6 {
public:
    BodyMoverBase(const char* name);
    virtual ~BodyMoverBase();
};
class BodyGyro : public BodyMoverBase {
public:
    BodyGyro();
private:
    float kP;
    float kD;
    G3D::Vector3 maxTorque;
    G3D::CoordinateFrame cframe;
};
BodyGyro::BodyGyro()
    : BodyMoverBase(sBodyGyro), kP(3000.0f), kD(500.0f), maxTorque(400000.0f, 0.0f, 400000.0f)
{
}
}
