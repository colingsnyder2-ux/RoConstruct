// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D { struct CoordinateFrame { float m[12]; }; }
namespace RBX {
class __declspec(novtable) ILocation {
public:
    virtual const G3D::CoordinateFrame getLocation() const = 0;
};
class __declspec(novtable) ICameraSubject : public virtual ILocation {
public:
    virtual ~ICameraSubject();
    virtual void onCameraNear(float distance);
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual const G3D::CoordinateFrame getRenderLocation() const;
};
const G3D::CoordinateFrame ICameraSubject::getRenderLocation() const
{
    return getLocation();
}
}
