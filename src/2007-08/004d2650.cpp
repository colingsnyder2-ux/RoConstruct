// from server: 100% by EspClaude
// roc 2007-08 004d2650  std::map<MaterialFactory::Attributes (0x10-byte variant), WeakReferenceCountedPointer<Material>>::find
// 2007 Attributes = 0x18 bytes: Color3 @0, int @0xc, 8-byte float pair @0x10; operator< compares the
// float-array members through their const float* conversions (pointer comparison, as the exe does).
#include <map>

namespace G3D {
class Color3 {
public:
    float r, g, b;
    operator const float*() const { return &r; }
};
class Vector2 {
public:
    float x, y;
    operator const float*() const { return &x; }
};
template<class T> class WeakReferenceCountedPointer {
public:
    T* pointer;
};
}

namespace RBX {
namespace Render { class Material; }
namespace View {
class MaterialFactory {
public:
    struct Attributes {
        G3D::Color3 color;
        int surface;
        bool operator<(const Attributes& other) const
        {
            if (surface < other.surface) return true;
            if (surface > other.surface) return false;
            return color < other.color;
        }
    };
};
}
}

typedef std::map<RBX::View::MaterialFactory::Attributes, G3D::WeakReferenceCountedPointer<RBX::Render::Material> > Database;
typedef Database::_Mybase Tree;
template Tree::iterator Tree::find(const Tree::key_type&);
