// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX {
class Surfaces { char pad[0x2e0]; public: int surfaceType[6]; };
class FaceInstance { Surfaces* part; int face; public: int getSurfaceType() const; };
int FaceInstance::getSurfaceType() const { return part->surfaceType[face]; }
}
