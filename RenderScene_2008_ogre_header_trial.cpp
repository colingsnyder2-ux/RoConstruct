// roc-cl: 21022
/*
 * Reconstructed high-level C++ from Roblox RenderScene (2008), 0x007AB0A0.
 * Real C++ only: no inline assembly or embedded machine code.
 * The Ogre declarations below are *interface placeholders* for a syntax check;
 * replace them with the correct versioned Ogre SDK headers before linking.
 * Roblox sub_... symbols require implementations/address bindings.
 * Not a verified byte-exact recreation.
 */

#include <string>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <stdexcept>

#if defined(_MSC_VER) && defined(_M_IX86)
#define RS_THISCALL __thiscall
#define RS_STDCALL __stdcall
#elif defined(__clang__) && defined(__i386__)
#define RS_THISCALL __attribute__((thiscall))
#define RS_STDCALL __attribute__((stdcall))
#else
#define RS_THISCALL
#define RS_STDCALL
#endif

#ifdef OGRE_NONCLIENT_BUILD
#undef OGRE_NONCLIENT_BUILD
#endif
#include <Ogre.h>


namespace rs {

typedef unsigned char u8;
typedef unsigned int u32;

template<class T>
inline T& At(void* p, unsigned offset) {
    return *reinterpret_cast<T*>(static_cast<unsigned char*>(p) + offset);
}

inline void* Addr(void* p, unsigned offset) {
    return static_cast<unsigned char*>(p) + offset;
}

template<class R>
inline R VCall(void* p, unsigned slot) {
    typedef R (RS_THISCALL *Fn)(void*);
    return reinterpret_cast<Fn>((*reinterpret_cast<void***>(p))[slot / 4])(p);
}

template<class R, class A>
inline R VCall(void* p, unsigned slot, A a) {
    typedef R (RS_THISCALL *Fn)(void*, A);
    return reinterpret_cast<Fn>((*reinterpret_cast<void***>(p))[slot / 4])(p, a);
}

template<class R, class A, class B>
inline R VCall(void* p, unsigned slot, A a, B b) {
    typedef R (RS_THISCALL *Fn)(void*, A, B);
    return reinterpret_cast<Fn>((*reinterpret_cast<void***>(p))[slot / 4])(p, a, b);
}

template<class R, class A, class B, class C, class D, class E>
inline R VCall(void* p, unsigned slot, A a, B b, C c, D d, E e) {
    typedef R (RS_THISCALL *Fn)(void*, A, B, C, D, E);
    return reinterpret_cast<Fn>((*reinterpret_cast<void***>(p))[slot / 4])(p, a, b, c, d, e);
}

struct RefNode { void* value; RefNode* next; };

// These are engine functions whose source/signatures have not been recovered.
// They must be linked to their original implementations or reconstructed.
extern "C" long RS_STDCALL rsInterlockedDecrement(volatile long* count);
extern void RS_THISCALL sub_5107B0(void* pose, void* matrix);
extern void* sub_6A0920(unsigned size);
extern void sub_6A067A(void* memory);
extern void* RS_THISCALL sub_674160(void* memory, void* renderer, const std::string& name);
extern void* RS_THISCALL sub_67D1F0(void* memory);
extern void RS_THISCALL sub_67C520(void* target, Ogre::MeshPtr mesh);
extern void RS_THISCALL sub_67C510(void* target, void* contextFields);
extern void* RS_THISCALL sub_67D9B0(void* target, void* mesh, int value);
extern void RS_THISCALL sub_7A9D30(void* scene, void* context, int flag);
extern void RS_THISCALL sub_7A9C40(void* target, Ogre::AxisAlignedBox box);
extern float* RS_THISCALL sub_7A9CE0(void* owner, void* key);
extern float* RS_THISCALL sub_7A9C90(void* owner, void* key);
extern void RS_THISCALL sub_548F80(void* ref, void** result, float value);
extern void RS_THISCALL sub_549A50(void* itemRef, void* ctx, Ogre::AxisAlignedBox* box);
extern void RS_THISCALL sub_549610(void* itemRef, void* ctx, Ogre::AxisAlignedBox* box);
extern void sub_5493E0(void* context);
extern void RS_STDCALL sub_54A920(void* context);
extern unsigned sub_513E20();
extern void RS_THISCALL sub_513220(void* output, unsigned value);
extern void RS_THISCALL sub_510B50(void* pose, void* timing);
extern void* sub_6A17C6(void* value);
extern void RS_THISCALL sub_45AD90(void* value);
extern int RS_STDCALL sub_6850D0(int distanceFlag);
extern void RS_THISCALL sub_6850B0(void* entity, int distanceFlag, void* mesh);
extern void RS_THISCALL sub_6850F0(void* entity, int distanceFlag);
extern void sub_55C4C0(std::string* out);

#if defined(_M_IX86) || defined(__i386__)
typedef char CheckAABBSize[(sizeof(Ogre::AxisAlignedBox) == 0x20) ? 1 : -1];
typedef char CheckMaterialHandleSize[(sizeof(Ogre::MaterialPtr) == 0x0c) ? 1 : -1];
typedef char CheckMeshHandleSize[(sizeof(Ogre::MeshPtr) == 0x0c) ? 1 : -1];
#endif

// These correspond to globals at 0x942EBC, 0x97F36C and 0x9738BC.
extern u8 gDebugRender;
extern unsigned gMaterialId;
extern Ogre::Mesh* gBaseMesh;

// A query has TWO outputs: the returned pointer to a value and the local
// ownership handle, which is subsequently decremented/destroyed. Mixing
// these two was a major bug in the earlier conversion.
struct QueryResult {
    void* handle;
    void* value;
};

inline QueryResult QueryItem(void* item, unsigned method) {
    QueryResult r = {0, 0};
    void* returned = VCall<void*>(item, method, &r.handle);
    if (returned)
        r.value = At<void*>(returned, 0);
    return r;
}

inline void ReleaseRef(void*& handle) {
    if (!handle)
        return;

    if (rsInterlockedDecrement(reinterpret_cast<volatile long*>(Addr(handle, 4))) == 0) {
        RefNode* node = At<RefNode*>(handle, 8);
        while (node) {
            RefNode* next = node->next;
            VCall<void>(node->value, 4);
            sub_6A067A(node);
            node = next;
        }
        VCall<void>(handle, 0, 1);
    }
    handle = 0;
}

// Some returned resources use a simpler release path rather than a RefNode list.
inline void ReleaseResource(void*& handle) {
    if (!handle)
        return;
    if (rsInterlockedDecrement(reinterpret_cast<volatile long*>(Addr(handle, 4))) == 0) {
        sub_45AD90(handle);
        VCall<void>(handle, 0, 1);
    }
    handle = 0;
}

inline Ogre::SubMesh* FindSubMesh(void* data) {
    if (!data || At<u8>(data, 0x1c) != 0)
        return 0;

    int index = At<int>(data, 0x20);
    if (index < 0 || !gBaseMesh)
        return 0;
    return gBaseMesh->getSubMesh(static_cast<unsigned short>(index));
}

// The virtual material-container method has five stack arguments in the
// original disassembly (index, 0, global, global, 0).
inline void* SelectMaterialEntry(void* container, int index) {
    return VCall<void*>(container, 0x14,
        index, 0,
        reinterpret_cast<void*>(0x96BDFCu),
        reinterpret_cast<void*>(0x96BE2Cu), 0);
}

inline void* GetMaterialData(void* item, int index) {
    QueryResult q = QueryItem(item, 0x14);
    void* result = q.value ? sub_6A17C6(SelectMaterialEntry(q.value, index)) : 0;
    ReleaseRef(q.handle);
    return result;
}

inline Ogre::TexturePtr GetSkyTexture() {
    Ogre::TextureManager& textures = Ogre::TextureManager::getSingleton();
    Ogre::TexturePtr texture = textures.getByName("skysphmap");
    if (texture.isNull()) {
        std::string rootPath;
        sub_55C4C0(&rootPath);
        Ogre::Image image;
        image.load(rootPath + "Sky\\skyspheremap.jpg", "General");
        texture = textures.create("skysphmap", "General");
        if (!texture.isNull())
            texture->loadImage(image);
    }
    return texture;
}

inline void ConfigureSky(Ogre::Material* material, float intensity) {
    Ogre::Pass* pass = material->getTechnique(0)->createPass();
    pass->setDiffuse(intensity, intensity, intensity, intensity * 0.8f);
    pass->setAmbient(intensity, intensity, intensity);
    pass->setSceneBlending(0, 9);

    Ogre::TexturePtr sky = GetSkyTexture();
    if (!sky.isNull()) {
        Ogre::TextureUnitState* unit = pass->createTextureUnitState();
        unit->setTextureName(sky->getName(), 2);
        unit->setEnvironmentMap(true, 1);
    }
}

inline void ConfigurePass(Ogre::Pass* pass, void* layer, void* item, void* info) {
    float* color = VCall<float*>(layer, 0x18);
    float alpha = 1.0f - VCall<float>(layer, 0x28);
    pass->setDiffuse(color[0], color[1], color[2], alpha);
    pass->setAmbient(color[0], color[1], color[2]);

    int type = At<int>(info, 0x84);
    if (type >= 1 && type <= 3) {
        float b = VCall<float>(layer, 0x1c, 1.0f);
        float g = VCall<float>(layer, 0x1c, b);
        float r = VCall<float>(layer, 0x1c, g);
        pass->setSpecular(r, g, b, 1.0f);
        pass->setShininess(type == 2 ? 40.0f : 18.0f);
    } else {
        pass->setSpecular(0.75f, 0.75f, 0.75f, 1.0f);
        pass->setShininess(10.0f);
    }

    pass->setDepthBias(At<float>(item, 0x18) * -16.0f, 0.0f);
    if (VCall<float>(layer, 0x28) > 0.0f || type == 4) {
        pass->setSceneBlending(7, 9);
        pass->setDepthWriteEnabled(false);
    }

    QueryResult textureQuery = QueryItem(layer, 0x0c);
    if (textureQuery.value) {
        void* textureData = sub_6A17C6(textureQuery.value);
        Ogre::TexturePtr* texture = textureData
            ? reinterpret_cast<Ogre::TexturePtr*>(Addr(textureData, 0x54)) : 0;

        if (texture && !texture->isNull()) {
            Ogre::TextureUnitState* unit = pass->createTextureUnitState();
            unit->setColourOperation(2);
            unit->setTextureFiltering(2, 2, 2);
            unit->setTextureAddressingMode(0, 0, 0);
            float* rgb = VCall<float*>(layer, 0x18);
            unit->setTextureBorderColour(Ogre::ColourValue(rgb[0], rgb[1], rgb[2], 1.0f));
            unit->setTextureName((*texture)->getName(), 2);
            if ((*texture)->isLoaded() && VCall<float>(layer, 0x28) > 0.0f && type == 2) {
                pass->setSceneBlending(4);
                pass->setDepthWriteEnabled(true);
                pass->setAlphaRejectSettings(6, 1);
            }
        }
    }
    ReleaseResource(textureQuery.handle);
}

// materialData is the internal engine material object returned by sub_6A17C6.
// Its Ogre::MaterialPtr is embedded at +0x2C, underlying pointer at +0x30.
inline bool BuildItemMaterial(void* item, void* info, void* materialData) {
    if (!materialData || At<void*>(materialData, 0x30))
        return false;

    Ogre::MaterialPtr* material = reinterpret_cast<Ogre::MaterialPtr*>(Addr(materialData, 0x2c));
    char name[8];
#if defined(_MSC_VER)
    _snprintf(name, sizeof(name), "m%d", static_cast<int>(gMaterialId++));
#else
    std::snprintf(name, sizeof(name), "m%d", static_cast<int>(gMaterialId++));
#endif
    *material = Ogre::MaterialManager::getSingleton().create(name, "General");
    if (material->isNull())
        return false;

    QueryResult layers = QueryItem(item, 0x14);
    int count = layers.value ? VCall<int>(layers.value, 0x10) : 0;
    ReleaseRef(layers.handle);

    for (int i = 0; i < count; ++i) {
        QueryResult group = QueryItem(item, 0x14);
        void* entry = group.value ? SelectMaterialEntry(group.value, i) : 0;
        void* layer = entry ? sub_6A17C6(entry) : 0;
        ReleaseRef(group.handle);
        if (!layer)
            continue;

        Ogre::Technique* technique = (*material)->getTechnique(0);
        Ogre::Pass* pass = i == 0 ? technique->getPass(0) : technique->createPass();
        ConfigurePass(pass, layer, item, info);
    }

    float intensity = VCall<float>(materialData, 0x24);
    if (intensity > 0.0f)
        ConfigureSky(material->operator->(), VCall<float>(materialData, 0x24));
    return true;
}

// The pair passed to the backend has radius at +0 and center at +4.
// The previous conversion reversed these, changing the parameter layout.
struct BoundsInfo {
    float radius;
    Ogre::Vector3 center;
};

inline void UpdateItemBounds(void* backend, void* itemRef, void* data,
                             void* ctx, bool special) {
    if (!data || At<u8>(data, 0x1c) == 0)
        return;

    Ogre::AxisAlignedBox box;
    if (special)
        sub_549610(itemRef, ctx, &box);
    else
        sub_549A50(itemRef, ctx, &box);

    BoundsInfo b = {box.getHalfSize().length(), box.getCenter()};
    void* mesh = special ? static_cast<void*>(FindSubMesh(data)) : At<void*>(data, 0x24);
    VCall<void>(backend, 0x1c4, mesh, &b);
}

inline Ogre::Vector3 WorldPosition(void* item) {
    float* m = VCall<float*>(item, 0x1c);
    return Ogre::Vector3(m[9], m[10], m[11]);
}

// At 7AC6C0..7AC8C9 the original builds one of two AABBs, then merges
// it with the target's existing bounds. This was missing from the old code.
inline void MergeItemBounds(void* backend, void* target, void* item,
                            void* data, void* selectedMesh) {
    Ogre::Vector3 pos = WorldPosition(item);
    if (std::fabs(pos.x) >= 10000.0f ||
        std::fabs(pos.y) >= 10000.0f ||
        std::fabs(pos.z) >= 10000.0f)
        return;

    Ogre::AxisAlignedBox box;
    if (selectedMesh != At<void*>(data, 0x24)) {
        float* bounds = VCall<float*>(backend, 0x1c8, selectedMesh);
        float r = bounds[0];
        Ogre::Vector3 center(pos.x + bounds[1], pos.y + bounds[2], pos.z + bounds[3]);
        box = Ogre::AxisAlignedBox(
            Ogre::Vector3(center.x-r, center.y-r, center.z-r),
            Ogre::Vector3(center.x+r, center.y+r, center.z+r));
    } else {
        void* mesh = At<void*>(data, 0x24);
        box = Ogre::AxisAlignedBox(
            Ogre::Vector3(pos.x + At<float>(mesh, 0xcc),
                          pos.y + At<float>(mesh, 0xd0),
                          pos.z + At<float>(mesh, 0xd4)),
            Ogre::Vector3(pos.x + At<float>(mesh, 0xd8),
                          pos.y + At<float>(mesh, 0xdc),
                          pos.z + At<float>(mesh, 0xe0)));
    }
    sub_7A9C40(target, box);
}

inline float DetermineItemDistanceFlag(void* item, const unsigned char* poseData) {
    float* m = VCall<float*>(item, 0x1c);
    float x = m[9]  - At<float>(const_cast<unsigned char*>(poseData), 0x24);
    float y = m[10] - At<float>(const_cast<unsigned char*>(poseData), 0x28);
    float z = m[11] - At<float>(const_cast<unsigned char*>(poseData), 0x2c);
    float depth = -(x * At<float>(const_cast<unsigned char*>(poseData), 0x08) +
                    y * At<float>(const_cast<unsigned char*>(poseData), 0x14) +
                    z * At<float>(const_cast<unsigned char*>(poseData), 0x20));
    return !(depth < 80.0f) ? 1.0f : 0.0f;
}

inline void AddPerVertexOffsets(void* info, void* data) {
    if (At<int>(data, 0x18) != 5 || At<int>(data, 0x10) != 4)
        return;
    void* raw = At<void*>(data, 0x0c);
    if (!raw)
        return;
    float* offset = sub_7A9CE0(info, At<void*>(raw, 0));
    for (int i = 0; i < 4; ++i) {
        void* key = At<void*>(raw, i * 4);
        float* pos = sub_7A9C90(info, key);
        pos[0] += offset[0] * 0.06f;
        pos[1] += offset[1] * 0.06f;
        pos[2] += offset[2] * 0.06f;
    }
}

inline void UpdateEntityTransform(void* entity, void* item) {
    float* m = VCall<float*>(item, 0x1c);
    Ogre::Matrix3 rotation;
    std::memcpy(&rotation, m, sizeof(rotation));
    Ogre::Quaternion orientation;
    orientation.FromRotationMatrix(rotation);

    m = VCall<float*>(item, 0x1c);
    Ogre::Matrix4 transform;
    transform.makeTransform(
        Ogre::Vector3(m[9], m[10], m[11]),
        Ogre::Vector3(1.0f, 1.0f, 1.0f), orientation);
    std::memcpy(Addr(entity, 0xf0), &transform, sizeof(transform));
}

class RenderScene {
public:
    void Render(void* ctx, void* pose);
};

void RenderScene::Render(void* ctx, void* pose) {
    void** items = At<void**>(this, 0x08);
    int count = At<int>(this, 0x0c);
    void* renderer = At<void*>(ctx, 0x04);
    Ogre::Camera* camera = At<Ogre::Camera*>(ctx, 0x08);
    bool enabled = At<u8>(this, 0x2f4) != 0;
    bool special = At<u8>(ctx, 0x7f5) != 0;
    void* backend = At<void*>(this, 0x268);
    void* target = At<void*>(this, 0x26c);

    unsigned char matrixData[0x80];
    sub_5107B0(pose, matrixData);

    if (enabled) {
        VCall<void>(renderer, 0x268, 0x12);
        Ogre::ColourValue background(At<float>(this, 0x328),
            At<float>(this, 0x32c), At<float>(this, 0x330), 1.0f);
        VCall<void>(renderer, 0x278, &background);
    } else {
        VCall<void>(renderer, 0x268, 0);
    }

    Ogre::Quaternion cameraOrientation;
    cameraOrientation.FromRotationMatrix(*reinterpret_cast<Ogre::Matrix3*>(matrixData));
    camera->setOrientation(cameraOrientation);
    camera->setPosition(At<float>(matrixData, 0x24), At<float>(matrixData, 0x28),
                        At<float>(matrixData, 0x2c));

    VCall<void>(camera, 0x11c, At<float>(pose, 0x0c));
    VCall<void>(camera, 0x124, At<float>(pose, 0x10));
    union { float f; u32 word; } clip;
    clip.f = At<float>(pose, 0x04);
    VCall<void>(camera, 0x114, &clip.f);

    Ogre::Timer timer;
    timer.reset();

    if (!backend) {
        void* mem = sub_6A0920(0x248);
        backend = mem ? sub_674160(mem, renderer, std::string("rbxroot")) : 0;
        At<void*>(this, 0x268) = backend;
        void* registration = VCall<void*>(renderer, 0xb4);
        VCall<void>(registration, 0xc8, backend);
    }

    clip.word = (clip.word & 0xffffff00u) | At<u8>(this, 0x2f6);
    sub_7A9D30(this, ctx, static_cast<int>(clip.word));

    Ogre::MaterialPtr* baseMaterial = reinterpret_cast<Ogre::MaterialPtr*>(Addr(this, 0x270));
    if (At<void*>(this, 0x274) == 0)
        *baseMaterial = Ogre::MaterialManager::getSingleton().getByName("BaseWhite");

    Ogre::MeshPtr* dummyMesh = reinterpret_cast<Ogre::MeshPtr*>(Addr(this, 0x27c));
    if (At<void*>(this, 0x280) == 0)
        *dummyMesh = Ogre::MeshManager::getSingleton().load("rbxdummymesh", "General");

    if (!target && count != 0) {
        void* mem = sub_6A0920(0x2bc);
        target = mem ? sub_67D1F0(mem) : 0;
        At<void*>(this, 0x26c) = target;
        VCall<void>(backend, 0x130, target);
        sub_67C520(target, *dummyMesh);
    }

    // The first pass only obtains and releases each item's 0x18 reference.
    for (int i = 0; i < count; ++i) {
        if (!items[i])
            continue;
        QueryResult r = QueryItem(items[i], 0x18);
        ReleaseRef(r.handle);
    }

    if (gDebugRender && count != 0 && special) {
        sub_5493E0(ctx);
        sub_67C520(target, *dummyMesh);
        if (target && gBaseMesh && At<int>(target, 0x294) == 0)
            sub_7A9C40(target, gBaseMesh->getBounds());
    }

    // Pose update and lazily initialized zero-vector cache at 0x96F044.
    unsigned char poseData[0x80];
    sub_513220(poseData, sub_513E20());
    static float zero[3] = {0.0f, 0.0f, 0.0f};
    At<float>(poseData, 0x24) = zero[0];
    At<float>(poseData, 0x28) = zero[1];
    At<float>(poseData, 0x2c) = zero[2];
    sub_510B50(pose, poseData);

    for (int i = 0; i < count; ++i) {
        void* item = items[i];
        if (!item)
            continue;

        QueryResult visible = QueryItem(item, 0x18);
        bool hasVisual = visible.value != 0;
        ReleaseRef(visible.handle);

        QueryResult geometry = QueryItem(item, 0x14);
        bool hasGeometry = geometry.value != 0;
        ReleaseRef(geometry.handle);
        if (!hasVisual || !hasGeometry)
            continue;

        QueryResult valid = QueryItem(item, 0x14);
        bool accepted = valid.value && VCall<int>(valid.value, 0x18, 0.0f) != 0;
        ReleaseRef(valid.handle);
        if (!accepted)
            continue;

        QueryResult detail = QueryItem(item, 0x18);
        void* info = detail.handle;
        if (!info)
            continue;

        if (enabled && At<int>(info, 0x80) == 0)
            sub_54A920(ctx);

        int distanceFlag = 0;
        if (At<int>(info, 0x10) == 2)
            distanceFlag = DetermineItemDistanceFlag(item, poseData) != 0.0f ? 1 : 0;

        void* data = 0;
        sub_548F80(info, &data, static_cast<float>(distanceFlag));
        bool specialMaterial = At<int>(info, 0x84) == 4 && At<u8>(ctx, 0x806) == 0;
        if (specialMaterial && data && At<u8>(data, 0x1c)) {
            sub_548F80(info, &data, 0.0f);
            AddPerVertexOffsets(info, data);
        }

        bool boundsUpdated = data && At<u8>(data, 0x1c) != 0;
        if (boundsUpdated)
            UpdateItemBounds(backend, info, data, ctx, special);

        void* materialData = GetMaterialData(item, 0);
        bool materialCreated = BuildItemMaterial(item, info, materialData);
        void* entity = At<void*>(item, 0x10);

        if (!entity) {
            void* mesh = special ? static_cast<void*>(FindSubMesh(data))
                                 : (data ? At<void*>(data, 0x24) : 0);
            if (!mesh) {
                ReleaseRef(detail.handle);
                throw std::runtime_error("Please restart ROBLOX, if you changed your settings but have not restarted");
            }

            entity = sub_67D9B0(target, mesh, distanceFlag);
            if (entity) {
                if (special)
                    At<u8>(entity, 0x13c) = 0;
                At<u32>(entity, 0x140) = At<u32>(info, 0x80);
                if ((At<int>(info, 0x80) == 0 && At<int>(info, 0x84) == 1) ||
                     At<int>(info, 0x84) == 4)
                    At<u8>(entity, 0x13c) = 0;
                At<void*>(item, 0x10) = entity;
                At<void*>(item, 0x0c) = target;

                VCall<void>(entity, 0x48, VCall<float>(item, 0x24));
                MergeItemBounds(backend, target, item, data, mesh);
            }
        } else {
            if (boundsUpdated || !sub_6850D0(distanceFlag)) {
                void* mesh = special ? static_cast<void*>(FindSubMesh(data))
                                     : (data ? At<void*>(data, 0x24) : 0);
                if (mesh)
                    sub_6850B0(entity, distanceFlag, mesh);
            }
        }

        if (entity) {
            sub_6850F0(entity, distanceFlag);
            VCall<void>(entity, 0x48, VCall<float>(item, 0x24));
            if (materialData && (materialCreated ||
                    At<void*>(VCall<void*>(entity, 0x04), 0x04) == At<void*>(this, 0x274))) {
                Ogre::Material* mat = At<Ogre::Material*>(materialData, 0x30);
                if (mat) {
                    Ogre::SubEntity* part = reinterpret_cast<Ogre::SubEntity*>(entity);
                    part->setMaterialName(mat->getName());
                }
            }
            UpdateEntityTransform(entity, item);
        }
        ReleaseRef(detail.handle);
    }

    if (special && gDebugRender) {
        sub_5493E0(ctx);
        if (target)
            sub_67C520(target, *dummyMesh);
    }

    timer.getMicroseconds();
    timer.reset();
    if (target) {
        sub_67C510(target, Addr(ctx, 0x18));
        At<u8>(target, 0x279) = 0;
        VCall<void>(target, 0xd8, 1);
        At<float>(target, 0x29c) = enabled ? 15.0f : 20.0f;
        At<int>(target, 0x2a0) = enabled ? 0x258 : 0x28a;
    }

    Ogre::Root& root = Ogre::Root::getSingleton();
    if (root._fireFrameStarted()) {
        VCall<void>(At<void*>(ctx, 0x0c), 0x18);
        root._fireFrameEnded();
        timer.getMicroseconds();
    }
}

} // namespace rs

// Byte-match status: unmeasured; requires the original MSVC compiler and `roc check`.

