// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace G3D { template<class T> class Array { T* data; int num; int numAllocated; public:
 int size() const { return num; } T& operator[](int i) { return data[i]; } }; }
namespace RBX {
class Primitive;
class Geometry { char pad[0x1c]; G3D::Array<Primitive*> a; char pad2[0x38-0x28]; G3D::Array<Primitive*> b;
public: Primitive* getFirstB(); Primitive* getFirstA(); Primitive* getFirst(); };
Primitive* Geometry::getFirstB() { return b.size() > 0 ? b[0] : 0; }
Primitive* Geometry::getFirstA() { return a.size() > 0 ? a[0] : 0; }
Primitive* Geometry::getFirst() { if (b.size() > 0) return b[0]; if (a.size() > 0) return a[0]; return 0; }
}
