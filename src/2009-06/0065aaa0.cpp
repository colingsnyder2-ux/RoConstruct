// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <string>
__declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    static const Vector3& zero() { static Vector3 v(0, 0, 0); return v; }
};
class Matrix3 {
public:
    float elt[3][3];
    Matrix3(const Matrix3& m);
    static const Matrix3& identity();
};
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    CoordinateFrame();
    CoordinateFrame(const Vector3& t) : rotation(Matrix3::identity()), translation(t) {}
    void lookAt(const Vector3& target);
};
class GCamera {
public:
    GCamera();
    ~GCamera();
    void setNearPlaneZ(float z) { nearPlane = -z; }
    void setFarPlaneZ(float z) { farPlane = -z; }
    void setFieldOfView(float angle);
    void setCoordinateFrame(const CoordinateFrame& c);
    char pad[0xc];
    float nearPlane;
    float farPlane;
    char pad2[0x44 - 0x14];
};
inline float toRadians(float deg) { return deg * 3.1415926535898f / 180.0f; }
}
namespace RBX {
template<class T> class Countable {
    static long count;
public:
    Countable() { InterlockedIncrement(&count); }
    ~Countable() { InterlockedDecrement(&count); }
};
namespace Math { bool legalCameraCoord(const G3D::CoordinateFrame& c); }
}
namespace rbx { namespace signals {
class connection : RBX::Countable<connection> {
public:
    void* px;
    void* pn;
    connection() : px(0), pn(0) {}
    ~connection();
};
} }
namespace boost {
template<class T> class weak_ptr {
public:
    T* px;
    void* pn;
    weak_ptr() : px(0), pn(0) {}
    ~weak_ptr();
};
}
namespace RBX {
class GuidItemBase { public: virtual void g0(); char pad[0x10]; };
class Object { public: virtual void o0(); };
class DescribedBase { public: virtual void d0(); int descriptor; };
class Debugable { public: virtual void b0(); char pad[0x68]; };
class Instance : public GuidItemBase, public Object, public DescribedBase, public Debugable {
public:
    Instance();
    virtual ~Instance();
    void setName(const std::string& name);
};
class Mid : public Instance {
public:
    __forceinline Mid() {}
    virtual ~Mid() {}
    virtual void g0(); virtual void o0(); virtual void d0(); virtual void b0();
};
class IListener {
public:
    virtual void l0();
    rbx::signals::connection conn;
};
class CameraSubject;
class Camera : public Mid, public IListener {
public:
    enum CameraType { FIXED_CAMERA };
    G3D::GCamera gCamera;
    G3D::CoordinateFrame cameraGoal;
    G3D::CoordinateFrame cameraFocus;
    CameraType cameraType;
    boost::weak_ptr<CameraSubject> cameraSubject;
    Camera();
    virtual ~Camera() {}
    virtual void g0(); virtual void o0(); virtual void d0(); virtual void b0(); virtual void l0();
    void setGCameraCoordinateFrame(const G3D::CoordinateFrame& coord)
    {
        if (Math::legalCameraCoord(coord))
            gCamera.setCoordinateFrame(coord);
    }
};
Camera::Camera()
    : cameraFocus(G3D::Vector3(0, 0, -5)),
      cameraType(FIXED_CAMERA)
{
    setName("Camera");
    gCamera.setNearPlaneZ(-1.25);
    gCamera.setFarPlaneZ(-5000);
    gCamera.setFieldOfView(G3D::toRadians(60));
    G3D::CoordinateFrame cameraCoord(G3D::Vector3(0, 5, 5));
    cameraCoord.lookAt(G3D::Vector3::zero());
    setGCameraCoordinateFrame(cameraCoord);
}
}
