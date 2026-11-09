// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Local names were chosen to reproduce the /Od frame layout (MSVC orders locals by name hash).
// Analog for 00548150: builds a level's welded geometry and face normals with
// G3D::MeshAlg (createIndexArray 007baea0, computeWeld 007badc0,
// computeAdjacency 007b9940) and the strip/quad triangulator 00551010.
class Vec3 {
public:
    Vec3();
    Vec3(const Vec3& other);
    Vec3& operator=(const Vec3& other);
    Vec3 operator-(const Vec3& other) const;
    Vec3 cross(const Vec3& other) const;
    Vec3 direction() const;
    float x, y, z;
};

template<class T>
class Array {
public:
    Array();
    ~Array();
    int size() const;
    int length() const;
    void fastClear();
    void resize(int n);
    void append(const T& value);
    T& operator[](int n);
    T* data;
    int num;
    int numAllocated;
};

class LevelData {
public:
    int header[0x0c / 4];
    Array<int> indices;
    int type;
};

template<class T>
class Ref {
public:
    Ref& operator=(const Ref& other);
    T* operator->() const;
    T* pointer;
};

struct Face { int vertexIndex[3]; };
struct Edge { int data[4]; };
struct Vertex { int data[6]; };

class MeshAlg {
public:
    static void createIndexArray(int n, Array<int>& array, int start, int run, int skip);
    static void computeWeld(const Array<Vec3>& oldVertexPositions, Array<Vec3>& newVertexPositions,
                            Array<int>& r, Array<int>& toOld, double radius);
    static void computeAdjacency(const Array<Vec3>& vertexGeometry, const Array<int>& i46,
                                 Array<Face>& faceArray, Array<Edge>& edgeArray, Array<Vertex>& q);
};

void triangulate(Array<int>& source, int primitive, Array<int>& triangles);
extern Array<Vec3> slotFirst;

class Level {
public:
    void build(const Ref<LevelData>& data);
    int header[0x18 / 4];
    Array<Edge> edges;
    Array<Vec3> faceNormals;
    Array<Face> faces;
    Array<Vec3> vertices;
    Ref<LevelData> source;
};

void Level::build(const Ref<LevelData>& data)
{
    source = data;
    vertices.fastClear();
    Array<Vec3> node;
    for (int i = 0; i < data->indices.size(); ++i) {
        int index = data->indices[i];
        Vec3 v = slotFirst[index];
        node.append(v);
    }
    Array<int> i46;
    if (data->type == 2) {
        MeshAlg::createIndexArray(data->indices.size(), i46, 0, 1, 0);
    } else {
        Array<int> strip;
        MeshAlg::createIndexArray(data->indices.size(), strip, 0, 1, 0);
        triangulate(strip, data->type, i46);
    }
    Array<int> x;
    Array<int> r;
    Array<int> toOld;
    MeshAlg::computeWeld(node, vertices, r, toOld, 0.00001);
    for (int i = 0; i < i46.length(); ++i)
        i46[i] = r[i46[i]];
    Array<Vertex> q;
    MeshAlg::computeAdjacency(vertices, i46, faces, edges, q);
    for (int i = 0; i < edges.length(); ++i)
        for (int j = 0; j < 2; ++j)
            do {} while (0);
    faceNormals.resize(faces.length());
    for (int i = 0; i < faceNormals.size(); ++i) {
        Vec3 v[3];
        for (int j = 0; j < 3; ++j)
            v[j] = vertices[faces[i].vertexIndex[j]];
        faceNormals[i] = (v[1] - v[0]).cross(v[2] - v[0]).direction();
    }
}
