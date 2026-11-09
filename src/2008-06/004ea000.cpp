// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_4f8d4db74da0eac9.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <G3D/ReferenceCount.h>
#include <map>

namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(const Vector3& V) : x(V.x), y(V.y), z(V.z) {}
    operator float*() { return (float*)this; }
    operator const float*() const { return (const float*)this; }
};
class Vector2 {
public:
    float x, y;
    Vector2() {}
    Vector2(const Vector2& v) { x = v.x; y = v.y; }
    operator float*() { return (float*)this; }
    operator const float*() const { return (const float*)this; }
};
}
namespace RBX {
enum NormalId { NORM_X };
namespace Render { class Mesh : public G3D::ReferenceCountedObject {}; }
namespace View {
class PBBMesh;
template <class T, int N>
class MeshFactory
{
public:
    class DecalKey
    {
    private:
        G3D::Vector3 size; // 0x00
        NormalId face;     // 0x0c
    public:
        bool operator<(const DecalKey& other) const
        {
            if (face < other.face)
                return true;
            if (face > other.face)
                return false;
            return size < other.size;
        }
    };
    class TextureKey : protected DecalKey
    {
    private:
        G3D::Vector2 studsPerTile; // 0x10
    public:
        bool operator<(const TextureKey& other) const
        {
            if (studsPerTile < other.studsPerTile)
                return true;
            if (studsPerTile > other.studsPerTile)
                return false;
            return DecalKey::operator<(other);
        }
    };
    typedef std::map<TextureKey, G3D::ReferenceCountedPointer<Render::Mesh> > TextureCache;
    static TextureCache textureCache;
    static G3D::ReferenceCountedPointer<Render::Mesh>& get(const TextureKey& key) { return textureCache[key]; }
};
template class MeshFactory<PBBMesh, 4>;
}
}
