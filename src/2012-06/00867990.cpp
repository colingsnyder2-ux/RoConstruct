// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
namespace G3D {
class Vector3 { public: float x, y, z; Vector3() {} };
class Ray { public: Vector3 origin, direction; Ray() {} ~Ray(); };
}
namespace RBX {
class UIEvent;
class Pad { public: virtual ~Pad(); char pad[0x14c]; };
class ICameraOwner { public: virtual ~ICameraOwner(); };
class Workspace : public Pad, public ICameraOwner {};
class MouseCommand {
public:
    char pad[0x20];
    Workspace* workspace;
    static G3D::Ray getUnitMouseRay(const UIEvent& uiEvent, ICameraOwner* _workspace);
    G3D::Ray getUnitMouseRay(const UIEvent& uiEvent) const;
};
G3D::Ray MouseCommand::getUnitMouseRay(const UIEvent& uiEvent) const
{
    return getUnitMouseRay(uiEvent, workspace);
}
}
