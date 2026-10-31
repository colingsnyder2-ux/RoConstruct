// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
typedef short int16;
class Vector2int16 { public: int16 x; int16 y; };
class Vector3 { public: float x, y, z; };
class Ray { public: Vector3 origin; Vector3 direction; virtual ~Ray() {} };
class Rect2D {
public:
    float x0, y0, x1, y1;
    static Rect2D xyxy(float x0, float y0, float x1, float y1);
};
class GCamera {
public:
    Ray worldRay(float x, float y, const Rect2D& viewport) const;
};
}
namespace RBX {
class UIEvent {
public:
    int eventType;
    int pad;
    G3D::Vector2int16 mousePosition;
    int pad2;
    G3D::Vector2int16 windowSize;
};
class ICameraOwner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual const G3D::GCamera& getGCamera() const = 0;
};
class MouseCommand {
public:
    static G3D::Ray getUnitMouseRay(const UIEvent& uiEvent, ICameraOwner* _workspace);
};
G3D::Ray MouseCommand::getUnitMouseRay(const UIEvent& uiEvent, ICameraOwner* _workspace)
{
    return _workspace->getGCamera().worldRay(
        uiEvent.mousePosition.x,
        uiEvent.mousePosition.y,
        G3D::Rect2D::xyxy(0.0f, 0.0f, uiEvent.windowSize.x, uiEvent.windowSize.y)
    );
}
}
