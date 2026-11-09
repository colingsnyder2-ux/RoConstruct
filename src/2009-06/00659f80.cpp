// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D { class CoordinateFrame { public: float m[12]; }; }
namespace RBX {
class Instance { public: virtual ~Instance(); };
class CameraSubject {
public:
    virtual ~CameraSubject();
    virtual void a();
    virtual void onCameraUpdate(const G3D::CoordinateFrame& coord, const G3D::CoordinateFrame& focus);
};
struct Heartbeat;
class Camera {
public:
    char pad[0x50];
    G3D::CoordinateFrame cameraCoord;
    G3D::CoordinateFrame cameraFocus;
    char pad3[0xb4 - 0x80 - 0x30];
    Instance* cameraSubject;
    void onHeartbeat(const Heartbeat& event);
};
void Camera::onHeartbeat(const Heartbeat& event)
{
    if (cameraSubject) {
        if (CameraSubject* s = dynamic_cast<CameraSubject*>(cameraSubject))
            s->onCameraUpdate(cameraCoord, cameraFocus);
    }
}
}
