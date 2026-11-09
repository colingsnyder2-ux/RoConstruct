// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D { class Vector3 { public: float x, y, z; Vector3(const Vector3& o) : x(o.x), y(o.y), z(o.z) {} }; }
namespace RBX {
struct ClassDescriptor;
struct P0 { virtual ~P0(); char p[0x14]; };
struct P18 { virtual void b(); const ClassDescriptor* descriptor; };
struct P20 { virtual void c(); char p[0x68]; };
struct P8c { virtual void d(); };
struct VB { int v; };
struct Instance2 : public P0, public P18, public P20, public P8c, virtual public VB { char m[0x24]; };
struct Sub : virtual public VB { virtual void s(); };
class PartLike : public Instance2, public Sub {
public:
    PartLike(G3D::Vector3 size);
    char members[0x174];
};
template<class T> struct Described { static ClassDescriptor& classDescriptor(); };
template<class T> struct Counter { static int count; };
class __declspec(novtable) Wedge : public PartLike {
public:
    Wedge(G3D::Vector3 size);
};
Wedge::Wedge(G3D::Vector3 size) : PartLike(size)
{
    descriptor = &Described<Wedge>::classDescriptor();
    ++Counter<Wedge>::count;
}
}
