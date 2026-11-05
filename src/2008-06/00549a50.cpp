// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_32290385cfe42487.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Array.h>
#include <G3D/Vector2.h>
#include <G3D/Vector3.h>
#include <G3D/ReferenceCount.h>
#include <map>
#include <vector>
#include <stdio.h>

struct Extent { float x, y, z; };
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
                          struct Extent&, struct Extent&);
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
    const G3D::Array<unsigned>& vertexIndices = *reinterpret_cast<const G3D::Array<unsigned>*>(
        reinterpret_cast<char*>(this) + 0xc);
    std::vector<unsigned> indices3286;
    std::vector<unsigned short> ind16;
    std::vector<float> verts;
    std::vector<float> normals;
    std::vector<float> texCoords;
    std::map<unsigned, unsigned> vmap;
    unsigned c = 0;
    for (int k = 0; k < vertexIndices.size(); ++k) {
        if (vmap.find(vertexIndices[k]) == vmap.end()) {
            vmap[vertexIndices[k]] = c;
            ++c;
        }
    }
    std::vector<unsigned> unique(vmap.size());
    for (int k = 0; k < vertexIndices.size(); ++k)
        unique[vmap[vertexIndices[k]]] = vertexIndices[k];

    int k;
    if (engine->has32BitIndices()) {
        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) == 5) {
            indices3286.resize(vertexIndices.size() / 4 * 6);
            for (k = 0; k < vertexIndices.size(); k += 4) {
                int quad = k / 4;
                indices3286[quad*6] = vmap[vertexIndices[quad*4]];
                indices3286[quad*6+1] = vmap[vertexIndices[quad*4+1]];
                indices3286[quad*6+2] = vmap[vertexIndices[quad*4+3]];
                indices3286[quad*6+3] = vmap[vertexIndices[quad*4+3]];
                indices3286[quad*6+4] = vmap[vertexIndices[quad*4+1]];
                indices3286[quad*6+5] = vmap[vertexIndices[quad*4+2]];
            }
            verts.resize(unique.size() * 3);
            normals.resize(unique.size() * 3);
            texCoords.resize(unique.size() * 2);
            for (k = 0; k < static_cast<int>(unique.size()); ++k) {
                int j;
                for (j = 0; j < 3; ++j) {
                    verts[k*3+j] = nativeMeshVertices[unique[k]][j];
                    normals[k*3+j] = nativeMeshNormals[unique[k]][j];
                }
                for (j = 0; j < 2; ++j)
                    texCoords[k*2+j] = nativeMeshUVs[unique[k]][j];
            }
        } else if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) == 2) {
            indices3286.resize(vertexIndices.size());
            for (k = 0; k < vertexIndices.size(); ++k)
                indices3286[k] = vmap[vertexIndices[k]];
            verts.resize(unique.size() * 3);
            normals.resize(unique.size() * 3);
            texCoords.resize(unique.size() * 2);
            for (k = 0; k < static_cast<int>(unique.size()); ++k) {
                int j;
                for (j = 0; j < 3; ++j) {
                    verts[k*3+j] = nativeMeshVertices[unique[k]][j];
                    normals[k*3+j] = nativeMeshNormals[unique[k]][j];
                }
                for (j = 0; j < 2; ++j)
                    texCoords[k*2+j] = nativeMeshUVs[unique[k]][j];
            }
        }
    } else {
        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) == 5) {
            ind16.resize(vertexIndices.size() / 4 * 6);
            for (k = 0; k < vertexIndices.size(); k += 4) {
                int quad = k / 4;
                ind16[quad*6] = vmap[vertexIndices[quad*4]];
                ind16[quad*6+1] = vmap[vertexIndices[quad*4+1]];
                ind16[quad*6+2] = vmap[vertexIndices[quad*4+3]];
                ind16[quad*6+3] = vmap[vertexIndices[quad*4+3]];
                ind16[quad*6+4] = vmap[vertexIndices[quad*4+1]];
                ind16[quad*6+5] = vmap[vertexIndices[quad*4+2]];
            }
            verts.resize(unique.size() * 3);
            normals.resize(unique.size() * 3);
            texCoords.resize(unique.size() * 2);
            for (k = 0; k < static_cast<int>(unique.size()); ++k) {
                int j;
                for (j = 0; j < 3; ++j) {
                    verts[k*3+j] = nativeMeshVertices[unique[k]][j];
                    normals[k*3+j] = nativeMeshNormals[unique[k]][j];
                }
                for (j = 0; j < 2; ++j)
                    texCoords[k*2+j] = nativeMeshUVs[unique[k]][j];
            }
        } else if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) == 2) {
            ind16.resize(vertexIndices.size());
            for (k = 0; k < vertexIndices.size(); ++k)
                ind16[k] = vmap[vertexIndices[k]];
            verts.resize(unique.size() * 3);
            normals.resize(unique.size() * 3);
            texCoords.resize(unique.size() * 2);
            for (k = 0; k < static_cast<int>(unique.size()); ++k) {
                int j;
                for (j = 0; j < 3; ++j) {
                    verts[k*3+j] = nativeMeshVertices[unique[k]][j];
                    normals[k*3+j] = nativeMeshNormals[unique[k]][j];
                }
                for (j = 0; j < 2; ++j)
                    texCoords[k*2+j] = nativeMeshUVs[unique[k]][j];
            }
        }
    }
    Extent min, max;
    *reinterpret_cast<Ogre::SubMesh**>(reinterpret_cast<char*>(this) + 0x24) = engine->createSubMesh(
        &verts[0], unique.size(), &normals[0], 0, &texCoords[0],
        engine->has32BitIndices() ? 0 : &ind16[0],
        engine->has32BitIndices() ? &indices3286[0] : 0,
        engine->has32BitIndices() ? indices3286.size()/3 : ind16.size()/3,
        min, max);
    bounds.setMinimum(min.x, min.y, min.z);
    bounds.setMaximum(max.x, max.y, max.z);
    *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x1c) = false;
}
}
