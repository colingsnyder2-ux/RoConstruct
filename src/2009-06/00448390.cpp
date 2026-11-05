// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
namespace G3D {
class _WeakPtr {
public:
    inline virtual ~_WeakPtr() {}
protected:
    virtual void objectCollected() = 0;
};
template <class T>
class WeakReferenceCountedPointer : public _WeakPtr {
private:
    T* pointer;
    void zeroPointer();
public:
    ~WeakReferenceCountedPointer() { zeroPointer(); }
protected:
    virtual void objectCollected();
};
}
namespace RBX {
class BrickColor { public: int number; };
namespace Render { class Material; }
namespace View {
class MaterialFactory {
public:
    struct Attributes
    {
        const BrickColor color;
        const float transparency;
        const float reflectance;
        const int extra;
        bool operator<(const Attributes&) const;
    };
    std::map<Attributes, G3D::WeakReferenceCountedPointer<Render::Material> > database;
    void clear();
};
void MaterialFactory::clear() { database.clear(); }
}
}
