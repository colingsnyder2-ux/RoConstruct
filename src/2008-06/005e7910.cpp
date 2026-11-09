// from server: 100% by king_originala
namespace G3D {
struct System {
    static void __cdecl alignedFree(void*);
};

struct Array {
    void* data;
    int count;
    int capacity;
    ~Array();
};

inline Array::~Array()
{
    System::alignedFree(data);
    data = 0;
    count = 0;
    capacity = 0;
}
}

namespace RBX {
struct Geometry {
    int header;
    G3D::Array a;
    G3D::Array b;
    ~Geometry();
};

Geometry::~Geometry()
{
}
}
