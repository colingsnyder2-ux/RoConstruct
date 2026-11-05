// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace G3D { template<class T> class Array { T* data; int num; int numAllocated; public:
 int size() const { return num; } T& operator[](int i) { return data[i]; } }; }
namespace RBX {
class Primitive;
class Geometry;
struct Edge { char pad[0xc]; Geometry* g0; Geometry* g1; int i0; int i1; };
class Geometry { char pad[0x1c]; G3D::Array<Edge*> a; char pad2[0x38-0x28]; G3D::Array<Edge*> b;
public: Edge* getNextB(Edge* e); Edge* getNextA(Edge* e); };
Edge* Geometry::getNextB(Edge* e) { int i = (this == e->g0) ? e->i0 : e->i1; i++; return i < b.size() ? b[i] : 0; }
Edge* Geometry::getNextA(Edge* e) { int i = (this == e->g0) ? e->i0 : e->i1; i++; return i < a.size() ? a[i] : 0; }
}
