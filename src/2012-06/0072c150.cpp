// from server: 100% by Xemicl
// roc 2012-06 0072c150  unit: RBX::Accoutrement  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0072c150
//
// 0072c150  8b4104               mov eax, dword ptr [ecx + 4]
// 0072c153  8b5004               mov edx, dword ptr [eax + 4]
// 0072c156  8b440a04             mov eax, dword ptr [edx + ecx + 4]
// 0072c15a  8d4c0a04             lea ecx, [edx + ecx + 4]
// 0072c15e  8b10                 mov edx, dword ptr [eax]
// 0072c160  56                   push esi
// 0072c161  8b742408             mov esi, dword ptr [esp + 8]
// 0072c165  56                   push esi
// 0072c166  ffd2                 call edx
// 0072c168  8bc6                 mov eax, esi
// 0072c16a  5e                   pop esi
// 0072c16b  c20400               ret 4
// copied from an identical function in another client (function ?getRenderLocation@ICameraSubject@RBX@@UBE?BUCoordinateFrame@G3D@@XZ)

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