// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
// roc 2009-06 005ae860  unit: RBX::Mesh  size: 91 bytes
// implicit /Od copy ctor of a struct holding two G3D::Array<T*> members

namespace G3D {
template<class T> class Array {
    T* data;
    int num;
    int numAllocated;
public:
    Array();
    Array(const Array& other);
    ~Array();
};
}

namespace RBX {
struct MeshArrays {
    G3D::Array<void*> a;
    G3D::Array<void*> b;
};
MeshArrays* copyMeshArrays(const MeshArrays& o) { return new MeshArrays(o); }
}
