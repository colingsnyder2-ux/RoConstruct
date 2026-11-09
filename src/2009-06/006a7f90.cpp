// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
struct System { static void __cdecl alignedFree(void*); };
template<class T> struct Array {
    T* data; int num; int numAllocated;
    ~Array() { System::alignedFree(data); data = 0; num = 0; numAllocated = 0; }
};
}
template<class T> struct scoped_ptr {
    T* px;
    ~scoped_ptr() { delete px; }
};
struct Poly { virtual ~Poly(); };
struct Buffers { char pad[0x3c]; ~Buffers(); };
struct Mesh {
    virtual ~Mesh();
    int i4;
    scoped_ptr<Poly> a;
    int c, d;
    Buffers* buffers;
    G3D::Array<int> arr;
    scoped_ptr<Poly> b;
    static int count;
};
Mesh::~Mesh()
{
    --count;
    delete buffers;
}
