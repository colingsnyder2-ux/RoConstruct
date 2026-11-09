// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Analog for 0054a920: uploads the vertex vector (+0x68) and 16-bit index vector
// (+0x50) through VisualEngine::createSubMesh (0067c130, ten arguments) and
// stores the submesh at +0x80.
#include <vector>

struct Vec3 {
    float x, y, z;
    float& operator[](int i);
};

struct Extent { float x, y, z; };

class SubMesh;

class VisualEngine {
public:
    SubMesh* createSubMesh(const float* positions, unsigned vertexCount, const float* normals,
                           const float* colours, const float* uvs, const unsigned short* indices16,
                           const unsigned* indices32, unsigned triangleCount,
                           Extent& minimum, Extent& maximum);
};

class Level {
public:
    void upload(VisualEngine* engine);
    char header[0x50];
    std::vector<unsigned short> indices;
    std::vector<Vec3> vertices;
    SubMesh* subMesh;
};

void Level::upload(VisualEngine* engine)
{
    if (vertices.size() && indices.size()) {
        Extent min;
        Extent max;
        subMesh = engine->createSubMesh(&vertices[0][0], vertices.size(), 0, 0, 0,
                                        &indices[0], 0, indices.size() / 3, min, max);
    }
}
