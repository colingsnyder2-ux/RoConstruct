// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class headers were available, so every type below is a local
// minimal layout built from the disassembly's offsets. All class and member
// names are guesses except the mangled callees (PartInstance::getPartSizeXml
// and ReferenceCountedPointer<Texture>::setPointer).
#include <math.h>

namespace G3D {
class Vector3 {
public:
    float x, y, z;
};

class Texture;

template <class T>
class ReferenceCountedPointer {
    T* m_p;
    void setPointer(T* p);          // ?setPointer@...AAEXPAVTexture@2@@Z (private)
public:
    void assign(T* p) { setPointer(p); }
};
}

namespace RBX {
class PartInstance {
public:
    char pad[0x1dc];
    int shape;
    const G3D::Vector3& getPartSizeXml() const;
};
}

// INFERRED: the callers push 3 args and clean up 0xc bytes, so these are plain
// cdecl functions, not thiscall as the prompt's inferred declarations say.
extern "C" G3D::Texture* fn_004ef2b0(void* size, int a, void* b);
extern "C" G3D::Texture* fn_004edeb0(void* size, int a, void* b);
extern "C" G3D::Texture* fn_004eedb0(void* size, int a, void* b);
extern "C" G3D::Texture* fn_004ee3b0(void* size, int a, void* b);
extern "C" G3D::Texture* fn_004ef7b0(void* size, int a, void* b);
extern "C" G3D::Texture* fn_004ee8b0(void* size, int a, void* b);
extern "C" int __fastcall fn_004dc4e0(void* self, int unusedEdx, G3D::Texture* a1);

struct MeshInfo {           // INFERRED: object at self+0xd4
    char pad[0x130];
    int type;
    float scale[3];
};

struct TexInfo {            // INFERRED: object at self+0xd8
    char pad0[0x140];
    int v140;
    char pad1[0x16c - 0x144];
    char data[4];
};

struct PartView {           // INFERRED: class owning these members
    char pad0[0x1c];
    float radius;
    char pad1[0xbc - 0x20];
    RBX::PartInstance* part;
    char pad2[0xcc - 0xc0];
    G3D::ReferenceCountedPointer<G3D::Texture> tex;
    char pad3[4];
    MeshInfo* mesh;
    TexInfo* texInfo;
};

extern "C" void __fastcall fn_004f0540(PartView* self, int unusedEdx)
{
    if (!self->part)
        return;

    float size[3];
    const G3D::Vector3& s = self->part->getPartSizeXml();
    size[0] = s.x;
    size[1] = s.y;
    size[2] = s.z;

    MeshInfo* mesh = self->mesh;
    if (mesh) {
        size[0] *= mesh->scale[0];
        size[1] *= mesh->scale[1];
        size[2] *= mesh->scale[2];
    }

    if (!mesh) {
        TexInfo* ti = self->texInfo;
        switch (self->part->shape) {
        case 0:
            self->tex.assign(fn_004eedb0(size, ti->v140, ti->data));
            break;
        case 1:
            self->tex.assign(fn_004edeb0(size, ti->v140, ti->data));
            break;
        case 2:
            self->tex.assign(fn_004ef2b0(size, ti->v140, ti->data));
            break;
        default:
            break;
        }
    } else {
        TexInfo* ti = self->texInfo;
        G3D::Texture* t;
        switch (mesh->type) {
        case 0: t = fn_004ef7b0(size, ti->v140, ti->data); break;
        case 1: t = fn_004ee8b0(size, ti->v140, ti->data); break;
        case 2: t = fn_004ee3b0(size, ti->v140, ti->data); break;
        case 3: t = fn_004eedb0(size, ti->v140, ti->data); break;
        case 4: t = fn_004ef2b0(size, ti->v140, ti->data); break;
        case 6: t = fn_004edeb0(size, ti->v140, ti->data); break;
        default: goto done;
        }
        fn_004dc4e0(&self->tex, 0, t);
    }
done:
    // INFERRED: constants at 0x826fd0 (double, sqrt'd at runtime) and 0x819bac (float)
    static const double kSqrtArg = 3.0;
    static const float kScale = 0.5f;
    float a = fabsf(size[0]);
    float b = fabsf(size[1]);
    float c = fabsf(size[2]);
    float m = (a > b) ? a : b;
    m = (m > c) ? m : c;
    self->radius = (float)(sqrt(kSqrtArg) * m) * kScale;
}
