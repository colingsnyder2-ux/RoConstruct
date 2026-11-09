// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { struct CoordinateFrame { char pad[0x30]; int x; };
class Body { public: void setPV(int* p); };
class Primitive { char pad[0xa0]; Body* body; public: void setCoordinateFrame(CoordinateFrame* c); void setPV(CoordinateFrame* c); };
void Primitive::setPV(CoordinateFrame* c) { body->setPV(&c->x); setCoordinateFrame(c); } }
