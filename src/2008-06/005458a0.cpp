// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-dll roc_mesh_level_upload_af64f429000cac4e.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Array.h>
#include <G3D/Vector2.h>
#include <G3D/Vector3.h>
#include <G3D/ReferenceCount.h>
#include <map>
#include <vector>
#include <stdio.h>

namespace Ogre {
class SubMesh;
// Genuine Ogre1.4.5 imported methods; this unit never instantiates the box.
class __declspec(dllimport) AxisAlignedBox {
public:
    void setMinimum(float, float, float);
    void setMaximum(float, float, float);
};
// Native 0054acf0 reads VisualEngine+7f4. 0067c130 has ten stack arguments
// (ret28h); its vertex/index buffer calls and bound writes establish this ABI.
class VisualEngine {
public:
    virtual ~VisualEngine();
    bool has32BitIndices();
    SubMesh* createSubMesh(const float*, unsigned, const float*, const float*, const float*,
                          const unsigned short*, const unsigned*, unsigned,
                          G3D::Vector3&, G3D::Vector3&);
};
}

namespace RBX {
extern G3D::Array<G3D::Vector3> nativeMeshVertices;
extern G3D::Array<G3D::Vector3> nativeMeshNormals;
extern G3D::Array<G3D::Vector2> nativeMeshUVs;
extern int nativeMeshUploadNumber;

// Opaque native Level. Actual ReferenceCountedObject prefix and observed fields
// are used; no unobserved backend members or allocation layout are declared.
class NativeMeshLevel : public G3D::ReferenceCountedObject {
public:
    void upload(Ogre::VisualEngine*, Ogre::AxisAlignedBox&);
};

void NativeMeshLevel::upload(Ogre::VisualEngine* engine, Ogre::AxisAlignedBox& bounds) {
    char name[8];
    sprintf(name, "m%d", nativeMeshUploadNumber++);
    const G3D::Array<unsigned>& source = *reinterpret_cast<const G3D::Array<unsigned>*>(
        reinterpret_cast<char*>(this) + 0xc);
    std::vector<unsigned> indices32;
    std::vector<unsigned short> indices16;
    std::vector<float> positions;
    std::vector<float> normals;
    std::vector<float> uv;
    std::map<unsigned, unsigned> remap;
    unsigned next = 0;
    for (int i = 0; i < source.size(); ++i) {
        if (remap.find(source[i]) == remap.end()) {
            remap[source[i]] = next;
            ++next;
        }
    }
    std::vector<unsigned> unique(remap.size());
    for (int i = 0; i < source.size(); ++i)
        unique[remap[source[i]]] = source[i];

    int i;
    if (engine->has32BitIndices()) {
        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) == 5) {
            indices32.resize(source.size() / 4 * 6);
            for (i = 0; i < source.size(); i += 4) {
                int quad = i / 4;
                indices32[quad*6] = remap[source[quad*4]];
                indices32[quad*6+1] = remap[source[quad*4+1]];
                indices32[quad*6+2] = remap[source[quad*4+3]];
                indices32[quad*6+3] = remap[source[quad*4+3]];
                indices32[quad*6+4] = remap[source[quad*4+1]];
                indices32[quad*6+5] = remap[source[quad*4+2]];
            }
            positions.resize(unique.size() * 3);
            normals.resize(unique.size() * 3);
            uv.resize(unique.size() * 2);
            for (i = 0; i < static_cast<int>(unique.size()); ++i) {
                int j;
                for (j = 0; j < 3; ++j) {
                    positions[i*3+j] = nativeMeshVertices[unique[i]][j];
                    normals[i*3+j] = nativeMeshNormals[unique[i]][j];
                }
                for (j = 0; j < 2; ++j)
                    uv[i*2+j] = nativeMeshUVs[unique[i]][j];
            }
        } else if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) == 2) {
            indices32.resize(source.size());
            for (i = 0; i < source.size(); ++i)
                indices32[i] = remap[source[i]];
            positions.resize(unique.size() * 3);
            normals.resize(unique.size() * 3);
            uv.resize(unique.size() * 2);
            for (i = 0; i < static_cast<int>(unique.size()); ++i) {
                int j;
                for (j = 0; j < 3; ++j) {
                    positions[i*3+j] = nativeMeshVertices[unique[i]][j];
                    normals[i*3+j] = nativeMeshNormals[unique[i]][j];
                }
                for (j = 0; j < 2; ++j)
                    uv[i*2+j] = nativeMeshUVs[unique[i]][j];
            }
        }
    } else {
        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) == 5) {
            indices16.resize(source.size() / 4 * 6);
            for (i = 0; i < source.size(); i += 4) {
                int quad = i / 4;
                indices16[quad*6] = remap[source[quad*4]];
                indices16[quad*6+1] = remap[source[quad*4+1]];
                indices16[quad*6+2] = remap[source[quad*4+3]];
                indices16[quad*6+3] = remap[source[quad*4+3]];
                indices16[quad*6+4] = remap[source[quad*4+1]];
                indices16[quad*6+5] = remap[source[quad*4+2]];
            }
            positions.resize(unique.size() * 3);
            normals.resize(unique.size() * 3);
            uv.resize(unique.size() * 2);
            for (i = 0; i < static_cast<int>(unique.size()); ++i) {
                int j;
                for (j = 0; j < 3; ++j) {
                    positions[i*3+j] = nativeMeshVertices[unique[i]][j];
                    normals[i*3+j] = nativeMeshNormals[unique[i]][j];
                }
                for (j = 0; j < 2; ++j)
                    uv[i*2+j] = nativeMeshUVs[unique[i]][j];
            }
        } else if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) == 2) {
            indices16.resize(source.size());
            for (i = 0; i < source.size(); ++i)
                indices16[i] = remap[source[i]];
            positions.resize(unique.size() * 3);
            normals.resize(unique.size() * 3);
            uv.resize(unique.size() * 2);
            for (i = 0; i < static_cast<int>(unique.size()); ++i) {
                int j;
                for (j = 0; j < 3; ++j) {
                    positions[i*3+j] = nativeMeshVertices[unique[i]][j];
                    normals[i*3+j] = nativeMeshNormals[unique[i]][j];
                }
                for (j = 0; j < 2; ++j)
                    uv[i*2+j] = nativeMeshUVs[unique[i]][j];
            }
        }
    }
    G3D::Vector3 minimum, maximum;
    *reinterpret_cast<Ogre::SubMesh**>(reinterpret_cast<char*>(this) + 0x24) = engine->createSubMesh(
        &positions[0], unique.size(), &normals[0], 0, &uv[0],
        engine->has32BitIndices() ? 0 : &indices16[0],
        engine->has32BitIndices() ? &indices32[0] : 0,
        engine->has32BitIndices() ? indices32.size()/3 : indices16.size()/3,
        minimum, maximum);
    bounds.setMinimum(minimum.x, minimum.y, minimum.z);
    bounds.setMaximum(maximum.x, maximum.y, maximum.z);
    *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x1c) = false;
}
}
