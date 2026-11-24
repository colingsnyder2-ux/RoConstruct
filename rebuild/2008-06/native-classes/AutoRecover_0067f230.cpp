// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers were provided for this class or for Ogre, so the types below are
// minimal file-local stand-ins. Field offsets come from the disassembly.
#include <string>

namespace Ogre {
    class Resource;
    template <class T> class SharedPtr {
    public:
        T* pRep; int* pUseCount;
    };
    class SubMesh {
    public:
        __declspec(dllimport) const std::string& getMaterialName() const;
    };
    class Mesh {
    public:
        __declspec(dllimport) SubMesh* getSubMesh(unsigned short index) const;
    };
    class Material {
    public:
        __declspec(dllimport) void setSceneBlending(int src, int dst);
        __declspec(dllimport) void setSceneBlending(int type);
    };
    class MeshPtr : public SharedPtr<Mesh> {
    public:
        __declspec(dllimport) MeshPtr(const SharedPtr<Resource>& r);
        __declspec(dllimport) virtual ~MeshPtr();
        Mesh* operator->() const { return pRep; }
        bool isNull() const { return pRep == 0; }
    };
    class MaterialPtr : public SharedPtr<Material> {
    public:
        __declspec(dllimport) MaterialPtr(const SharedPtr<Resource>& r);
        __declspec(dllimport) virtual ~MaterialPtr();
        Material* operator->() const { return pRep; }
    };
    class ColourValue {
    public:
        float r, g, b, a;
    };
    class Billboard {
    public:
        __declspec(dllimport) void setColour(const ColourValue& c);
    };
    class BillboardSet {
    public:
        virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
        virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
        virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
        virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f();
        virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
        virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
        virtual void v18(); virtual void v19(); virtual void v1a(); virtual void v1b();
        virtual void v1c(); virtual void v1d(); virtual void v1e(); virtual void v1f();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28(); virtual void v29(); virtual void v2a(); virtual void v2b();
        virtual void v2c(); virtual void v2d(); virtual void v2e(); virtual void v2f();
        virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
        virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
        virtual void v38(); virtual void v39(); virtual void v3a(); virtual void v3b();
        virtual void v3c(); virtual void v3d(); virtual void v3e(); virtual void v3f();
        virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
        virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
        virtual void v48(); virtual void v49(); virtual void v4a(); virtual void v4b();
        virtual void v4c(); virtual void v4d(); virtual void v4e(); virtual void v4f();
        virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
        virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57();
        virtual void v58(); virtual void v59(); virtual void v5a(); virtual void v5b();
        virtual void v5c(); virtual void v5d(); virtual void v5e(); virtual void v5f();
        virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
        virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
        virtual void v68(); virtual void v69(); virtual void v6a(); virtual void v6b();
        virtual void v6c(); virtual void v6d(); virtual void v6e(); virtual void v6f();
        virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73();
        virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
        virtual void v78(); virtual void v79(); virtual void v7a(); virtual void v7b();
        virtual void v7c(); virtual void v7d(); virtual void v7e(); virtual void v7f();
        virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
        virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
        virtual void v88(); virtual void v89(); virtual void v8a(); virtual void v8b();
        virtual void v8c(); virtual void v8d(); virtual void v8e(); virtual void v8f();
        virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93();
        virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97();
        virtual void v98(); virtual void v99(); virtual void v9a(); virtual void v9b();
        virtual void v9c(); virtual void v9d(); virtual void v9e(); virtual void v9f();
        virtual void va0(); virtual void va1(); virtual void va2(); virtual void va3();
        virtual void va4(); virtual void va5(); virtual void va6(); virtual void va7();
        virtual void va8(); virtual void va9(); virtual void vaa(); virtual void vab();
        virtual void vac(); virtual void vad(); virtual void vae(); virtual void vaf();
        virtual void vb0(); virtual void vb1(); virtual void vb2(); virtual void vb3();
        virtual void vb4(); virtual void vb5(); virtual void vb6(); virtual void vb7();
        virtual void vb8(); virtual void vb9(); virtual void vba(); virtual void vbb();
        virtual void vbc(); virtual void vbd(); virtual void vbe(); virtual void vbf();
        virtual void vc0(); virtual void vc1(); virtual void vc2(); virtual void vc3();
        virtual void vc4(); virtual void vc5(); virtual void vc6(); virtual void vc7();
        virtual void vc8(); virtual void vc9(); virtual void vca(); virtual void vcb();
        virtual void vcc(); virtual void vcd(); virtual void vce(); virtual void vcf();
        virtual void vd0(); virtual void vd1(); virtual void vd2(); virtual void vd3();
        virtual void vd4(); virtual void vd5(); virtual void vd6(); virtual void vd7();
        virtual void vd8(); virtual void vd9(); virtual void vda(); virtual void vdb();
        virtual void vdc(); virtual void vdd(); virtual void vde(); virtual void vdf();
        virtual void ve0(); virtual void ve1(); virtual void ve2(); virtual void ve3();
        virtual void ve4(); virtual void ve5(); virtual void ve6(); virtual void ve7();
        virtual void ve8(); virtual void ve9(); virtual void vea(); virtual void veb();
        virtual void vec(); virtual void ved(); virtual void vee(); virtual void vef();
        virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3();
        virtual void vf4(); virtual void vf5(); virtual void vf6(); virtual void vf7();
        virtual Billboard* getBillboard(int index);
    };
    class SceneNode {
    public:
        virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
        virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
        virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
        virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f();
        virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
        virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
        virtual void v18(); virtual void v19();
        virtual void setScale(float x, float y, float z);
    };
    class MeshManager {
    public:
        __declspec(dllimport) static MeshManager& getSingleton();
        virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
        virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
        virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
        virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f();
        virtual void v10(); virtual void v11(); virtual void v12();
        virtual SharedPtr<Resource> getByName(const std::string& name);
    };
    class MaterialManager {
    public:
        __declspec(dllimport) static MaterialManager& getSingleton();
        virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
        virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
        virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
        virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f();
        virtual void v10(); virtual void v11(); virtual void v12();
        virtual SharedPtr<Resource> getByName(const std::string& name);
    };
}

struct StarsOwner {
    char pad0[0x38];
    Ogre::BillboardSet* billboards;   // +0x38
    char pad1[0x44 - 0x3c];
    Ogre::SceneNode* node;            // +0x44
    char pad2[0x85 - 0x48];
    bool starsVisible;                // +0x85
    char pad3[0xc8 - 0x86];
    float outA, outB, outC;           // +0xc8..0xd0
};

struct SkyParams {
    char pad0[0xc];
    float timeOfDay;      // +0x0c
    float f10;            // +0x10
    char pad1[0x4c - 0x14];
    bool useFirst;        // +0x4c
    char pad2[0x68 - 0x4d];
    float colA[3];        // +0x68
    float colB[3];        // +0x74
    float starAlpha;      // +0x78
};

// INFERRED: float constants live in .rdata; values are guesses.
static const float kStarThreshold = 0.0f;   // 0x84e55c
static const float kDayStart = 0.0f;        // 0x82711c
static const float kDayEnd = 1.0f;          // 0x8288b8
static const float kBias = 0.0f;            // 0x81e704
static const float kScale = 1.0f;           // 0x826cb4

extern "C" void __fastcall fn_0067f230(StarsOwner* self, int unusedEdx, SkyParams* p, int arg2)
{
    if (p->starAlpha > kStarThreshold) {
        self->starsVisible = true;

        std::string name("starsMesh");
        Ogre::MeshPtr mesh(Ogre::MeshManager::getSingleton().getByName(name));

        if (!mesh.isNull()) {
            if (p->timeOfDay > kDayStart && kDayEnd > p->timeOfDay) {
                for (int i = 0; i < 3; ++i) {
                    Ogre::MaterialManager& mm = Ogre::MaterialManager::getSingleton();
                    Ogre::MaterialPtr mat(mm.getByName(mesh->getSubMesh((unsigned short)i)->getMaterialName()));
                    mat->setSceneBlending(4, 1);
                }
            } else {
                for (int i = 0; i < 3; ++i) {
                    Ogre::MaterialManager& mm = Ogre::MaterialManager::getSingleton();
                    Ogre::MaterialPtr mat(mm.getByName(mesh->getSubMesh((unsigned short)i)->getMaterialName()));
                    mat->setSceneBlending(4);
                }
            }
        }
    } else {
        self->starsVisible = false;
    }

    const float* c = p->useFirst ? p->colA : p->colB;
    float x = c[0], y = c[1], z = c[2];

    float t = 1.0f - p->f10 + kBias;
    float s = (t > 1.0f) ? 1.0f : t;

    self->node->setScale(x * kScale, y * kScale, z * kScale);

    Ogre::ColourValue col;
    col.r = s; col.g = s; col.b = s; col.a = 1.0f;
    self->billboards->getBillboard(0)->setColour(col);

    // INFERRED: stored values mirror the disassembly (first, second, second).
    self->outA = x * kScale;
    self->outB = y * kScale;
    self->outC = y * kScale;
}
