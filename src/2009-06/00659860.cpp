// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Instance { public: virtual ~Instance(); };
class CameraSubject { public: virtual ~CameraSubject(); };
class Camera {
public:
    char pad[0x140];
    Instance* cameraSubject;
    CameraSubject* getCameraSubject() const;
};
CameraSubject* Camera::getCameraSubject() const
{
    if (Instance* i = cameraSubject) return dynamic_cast<CameraSubject*>(i);
    return 0;
}
}
