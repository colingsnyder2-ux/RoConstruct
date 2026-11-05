// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
#include <string>
#include <vector>
#include <math.h>

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

namespace G3D {
struct Vector3 {
    float x, y, z;
    Vector3() {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
    Vector3 operator*(const Vector3& v) const { return Vector3(x * v.x, y * v.y, z * v.z); }
    Vector3& operator*=(const Vector3& v) { x *= v.x; y *= v.y; z *= v.z; return *this; }
};
class ReferenceCountedObject {
public:
    long refCount;
    virtual ~ReferenceCountedObject();
    void ReferenceCountedObject_zeroWeakPointers();
};
}

static inline float maxf(float a, float b) { return (a > b) ? a : b; }
namespace RBX {
enum NormalId { NORM_X, NORM_Y, NORM_Z, NORM_X_NEG, NORM_Y_NEG, NORM_Z_NEG };
enum SurfaceType { NO_SURFACE, STUDS, INLET, WELD, GLUE };
class BrickColor { public: int number; };
class Name;
class ContentId {
    std::string id;
    const Name* mimeTypePtr;
public:
    ContentId();
    ContentId& operator=(const ContentId&);
    bool isNull() const { return id.empty(); }
};
class MeshId : public ContentId {};

class Instance;
struct InstancePtr { Instance* px; void* pn; Instance* get() const { return px; } };
class Instances : public std::vector<InstancePtr> {
public:
    const_iterator begin() const;
    const_iterator end() const;
};

class Instance {
public:
    virtual ~Instance();
    char pad[0x100];
    Instance* parent;
    Instances* children;
    Instance* getParent() const { return parent; }
    Instances* getChildren() const { return children; }
};
class ModelInstance : public Instance { public: void* findModelModifier(); };
class Clothing : public Instance {
    char pad2[0x134 - 0x10c];
public:
    ContentId shirt;
    ContentId pants;
};
class SurfaceView { public: SurfaceType getSurfaceType() const; };
class SurfacesView { public: const SurfaceView& operator[](NormalId) const; };
class PartInstance : public Instance {
public:
    char pad3[0x1dc - 0x10c];
    int shape;
    char pad4[4];
    BrickColor color;
    BrickColor getColor() const { return color; }
    const SurfacesView& getSurfaces() const;
    const G3D::Vector3& getPartSizeXml() const;
};
class Humanoid {
public:
    static Humanoid* fromInstance(Instance*);
    PartInstance* getTorso() const;
    PartInstance* getLeftLeg() const;
    PartInstance* getRightLeg() const;
    PartInstance* getLeftArm() const;
    PartInstance* getRightArm() const;
};
class ContentProvider { public: static ContentProvider* find(Instance*); };
class SpecialShape : public Instance {
public:
    char pad5[0x130 - 0x10c];
    int meshType;
    G3D::Vector3 scale;
    MeshId getMeshId() const;
    const G3D::Vector3& getScale() const { return scale; }
};

namespace RenderBase { class Mesh : public G3D::ReferenceCountedObject {}; }
class SphereMesh : public RenderBase::Mesh {};
class BlockMesh : public RenderBase::Mesh {};
class CylinderMesh : public RenderBase::Mesh {};
class HeadMesh : public RenderBase::Mesh {};
class TorsoMesh : public RenderBase::Mesh {};
class WedgeMesh : public RenderBase::Mesh {};

struct InlineMeshRef;
struct MeshRef {
    RenderBase::Mesh* m_pointer;
    void setPointer(RenderBase::Mesh*);
    template<class S> MeshRef& operator=(S*);
    MeshRef& assign(const MeshRef&);
    inline const MeshRef& operator=(const MeshRef& p) { setPointer(p.m_pointer); return *this; }
    inline const MeshRef& operator=(const InlineMeshRef& p);
    ~MeshRef();
    __forceinline void set(RenderBase::Mesh* p) { setPointer(p); }
};
struct InlineMeshRef {
    RenderBase::Mesh* m_pointer;
    __forceinline ~InlineMeshRef() {
        if (m_pointer) {
            if (InterlockedDecrement(&m_pointer->refCount) == 0) {
                m_pointer->ReferenceCountedObject_zeroWeakPointers();
                delete m_pointer;
            }
        }
    }
};

struct PartPtr { PartInstance* px; void* pn; PartInstance* get() const { return px; } PartInstance* operator->() const { return px; } };
inline const MeshRef& MeshRef::operator=(const InlineMeshRef& p) { setPointer(p.m_pointer); return *this; }
namespace ViewNew {
class RenderSurfaceTypes {
public:
    unsigned data;
    RenderSurfaceTypes() : data(0) {}
    void setSurfaceType(NormalId id, int type) {
        data = (data & static_cast<unsigned short>(~(7u << (3 * id)))) | (type << (3 * id));
    }
};
static inline int renderSurfaceType(SurfaceType type) {
    switch (type) {
    case STUDS: return 1;
    case INLET: return 2;
    case WELD: return 3;
    case GLUE: return 4;
    default: return 0;
    }
}
SphereMesh* createSphere(const G3D::Vector3&, RenderSurfaceTypes);
BlockMesh* createBlock(const G3D::Vector3&, RenderSurfaceTypes);
CylinderMesh* createCylinder(const G3D::Vector3&, RenderSurfaceTypes);
HeadMesh* createHead(const G3D::Vector3&, RenderSurfaceTypes);
TorsoMesh* createTorso(const G3D::Vector3&, RenderSurfaceTypes);
WedgeMesh* createWedge(const G3D::Vector3&, RenderSurfaceTypes);
InlineMeshRef createBrick0(const G3D::Vector3&, RenderSurfaceTypes, BrickColor);
MeshRef createBrick(const G3D::Vector3&, RenderSurfaceTypes, BrickColor);
MeshRef createClothed(const G3D::Vector3&, RenderSurfaceTypes, BrickColor, const int*, const float*, const int*, float);
MeshRef createFileMesh(ContentProvider*, const G3D::Vector3&, MeshId);
extern const int torsoIndices[], torsoFlags[], leftLegIndices[], leftLegFlags[], rightLegIndices[], rightLegFlags[];
extern const int leftArmIndices[], leftArmFlags[], rightArmIndices[], rightArmFlags[];
extern const float atlasRects[];

class Part {
public:
    char pad[0x1c];
    float radius;
    char pad2[0xbc - 0x20];
    PartPtr partInstance;
    void* material;
    bool materialInvalid;
    MeshRef mesh;
    void* view;
    SpecialShape* specialShape;
    bool usesMegaTexture() const;
    void updateMesh();
};

void Part::updateMesh()
{
    RenderSurfaceTypes surfaces;
    surfaces.setSurfaceType(NORM_X, renderSurfaceType(partInstance->getSurfaces()[NORM_X].getSurfaceType()));
    surfaces.setSurfaceType(NORM_Y, renderSurfaceType(partInstance->getSurfaces()[NORM_Y].getSurfaceType()));
    surfaces.setSurfaceType(NORM_Z, renderSurfaceType(partInstance->getSurfaces()[NORM_Z].getSurfaceType()));
    surfaces.setSurfaceType(NORM_X_NEG, renderSurfaceType(partInstance->getSurfaces()[NORM_X_NEG].getSurfaceType()));
    surfaces.setSurfaceType(NORM_Y_NEG, renderSurfaceType(partInstance->getSurfaces()[NORM_Y_NEG].getSurfaceType()));
    surfaces.setSurfaceType(NORM_Z_NEG, renderSurfaceType(partInstance->getSurfaces()[NORM_Z_NEG].getSurfaceType()));
    G3D::Vector3 size = partInstance->getPartSizeXml();

    if (usesMegaTexture())
    {
        Instance* parent = partInstance->getParent();
        void* modifier = 0;
        Humanoid* humanoid = 0;
        if (parent)
        {
            ModelInstance* model = dynamic_cast<ModelInstance*>(parent);
            modifier = model ? model->findModelModifier() : 0;
            humanoid = Humanoid::fromInstance(parent);
        }
        if (!modifier || !humanoid)
        {
            mesh = createBrick0(size, surfaces, partInstance->getColor());
        }
        else
        {
            ContentId shirt;
            ContentId pants;
            if (parent->getChildren())
            {
                Instances::const_iterator end = parent->getChildren()->end();
                Instances::const_iterator begin = parent->getChildren()->begin();
                for (Instances::const_iterator it = begin; it != end; ++it)
                {
                    if (Clothing* clothing = dynamic_cast<Clothing*>(it->get()))
                    {
                        if (shirt.isNull() && !clothing->shirt.isNull())
                            shirt = clothing->shirt;
                        if (pants.isNull() && !clothing->pants.isNull())
                            pants = clothing->pants;
                    }
                }
            }
            if ((partInstance.get() == humanoid->getTorso() && (!shirt.isNull() || !pants.isNull()))
                || (partInstance.get() == humanoid->getLeftLeg() && !pants.isNull())
                || (partInstance.get() == humanoid->getRightLeg() && !pants.isNull())
                || (partInstance.get() == humanoid->getLeftArm() && !shirt.isNull())
                || (partInstance.get() == humanoid->getRightArm() && !shirt.isNull()))
            {
                RenderSurfaceTypes noSurfaces;
                if (partInstance.get() == humanoid->getTorso())
                    mesh = createClothed(size, noSurfaces, partInstance->getColor(), torsoIndices, atlasRects, torsoFlags, 0.0063725486397743225f);
                else if (partInstance.get() == humanoid->getLeftLeg())
                    mesh = createClothed(size, noSurfaces, partInstance->getColor(), leftLegIndices, atlasRects, leftLegFlags, 0.0063725486397743225f);
                else if (partInstance.get() == humanoid->getRightLeg())
                    mesh.assign(createClothed(size, noSurfaces, partInstance->getColor(), rightLegIndices, atlasRects, rightLegFlags, 0.0063725486397743225f));
                else if (partInstance.get() == humanoid->getLeftArm())
                    mesh.assign(createClothed(size, noSurfaces, partInstance->getColor(), leftArmIndices, atlasRects, leftArmFlags, 0.0063725486397743225f));
                else if (partInstance.get() == humanoid->getRightArm())
                    mesh.assign(createClothed(size, noSurfaces, partInstance->getColor(), rightArmIndices, atlasRects, rightArmFlags, 0.0063725486397743225f));
            }
            else
            {
                mesh = createBrick(size, surfaces, partInstance->getColor());
            }
        }
    }
    else if (!specialShape)
    {
        switch (partInstance->shape)
        {
        case 0: mesh.set(createSphere(size, surfaces)); break;
        case 1: mesh.set(createBlock(size, surfaces)); break;
        case 2: mesh.set(createCylinder(size, surfaces)); break;
        }
    }
    else
    {
        size.x = specialShape->scale.x * size.x;
        size.y = specialShape->scale.y * size.y;
        size.z = specialShape->scale.z * size.z;
        switch (specialShape->meshType)
        {
        case 0: mesh = createHead(size, surfaces); break;
        case 1: mesh = createTorso(size, surfaces); break;
        case 2: mesh = createWedge(size, surfaces); break;
        case 3: mesh = createSphere(size, surfaces); break;
        case 4: mesh = createCylinder(size, surfaces); break;
        case 6: mesh = createBlock(size, surfaces); break;
        case 5: mesh.assign(createFileMesh(ContentProvider::find(partInstance.get()), specialShape->getScale(), specialShape->getMeshId())); break;
        }
    }

    float sqrt2 = sqrt(2.0);
    float x = fabs(size.x);
    float y = fabs(size.y);
    float z = fabs(size.z);
    radius = maxf(maxf(x, y), z) * sqrt2 * 0.5f;
}
}
}
