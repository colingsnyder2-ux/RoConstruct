// from server: 100% by Xemicl
// roc 2012-06 004cc560  unit: Ogre::RbxSceneManagerFactory  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004cc560
//
// 004cc560  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004cc564  8b442404             mov eax, dword ptr [esp + 4]
// 004cc568  d94124               fld dword ptr [ecx + 0x24]
// 004cc56b  d918                 fstp dword ptr [eax]
// 004cc56d  d94128               fld dword ptr [ecx + 0x28]
// 004cc570  d95804               fstp dword ptr [eax + 4]
// 004cc573  d9412c               fld dword ptr [ecx + 0x2c]
// 004cc576  d95808               fstp dword ptr [eax + 8]
// 004cc579  c3                   ret 
// copied from an identical function in another client (function ?getTranslation@@YA?AVVector3@G3D@@ABVCoordinateFrame@2@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 { public: float x, y, z;
  inline Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {} };
class Matrix3 { public: float elt[3][3]; };
class CoordinateFrame { public: Matrix3 rotation; Vector3 translation; };
}
G3D::Vector3 getTranslation(const G3D::CoordinateFrame& c)
{
    return c.translation;
}