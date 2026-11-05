// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Analog for 00552300 (AggregateChunk render): rebuilds the merged geometry
// when the lighting changes (shadow extrusion along -direction * lod), narrows
// indices to 16 bits when possible, uploads a VAR and draws it (G3D RenderDevice).
class Vec3 {
public:
    Vec3 direction() const;
    Vec3 operator-() const;
    Vec3 operator*(float s) const;
    float x, y, z;
};

class Lighting {
public:
    Vec3 lightDirection() const;
    bool operator!=(const Lighting& other) const;
    Lighting& operator=(const Lighting& other);
    int data[0x50 / 4];
};

template<class T>
class Array {
public:
    Array();
    ~Array();
    int size() const;
    void fastClear();
    void resize(int n);
    void append(const T& value);
    T& operator[](int n);
    T* data;
    int num;
    int numAllocated;
};

template<class T>
class Ref {
public:
    Ref(const Ref& other);
    ~Ref();
    T* operator->() const;
    T* pointer;
};

class VARArea {
public:
    static Ref<VARArea> create(unsigned size, int hint);
};

class VAR {
public:
    template<class T> VAR(const Array<T>& source, Ref<VARArea> area);
    VAR& operator=(const VAR& other);
    ~VAR();
    Ref<VARArea> area;
    int type;
    unsigned elementSize;
    unsigned numElements;
    unsigned __int64 generation;
    void* pointer;
    unsigned maxSize;
};

class CFrame;

class Owner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual bool hidden();
};

class Builder {
public:
    void build(const CFrame& frame, const Vec3& direction, Array<int>& indices, Array<Vec3>& vertices, bool caps);
};

class RenderDevice {
public:
    void beginIndexedPrimitives();
    void setVertexArray(const VAR& v);
    void sendIndices(int primitive, const Array<int>& indices);
    void sendIndices(int primitive, const Array<unsigned short>& indices);
    void endIndexedPrimitives();
};

class AggregateChunk {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual const CFrame& frame();
    void render(RenderDevice* rd, const Lighting& lighting, bool caps, float lod);
    int header[0x20 / 4];
    Ref<Owner> owner;
    Ref<Builder> builder;
    int middle[0x38 / 4];
    Lighting lastLighting;
    VAR vertexArray;
    Array<int> indices;
    Array<unsigned short> shortIndices;
};

void AggregateChunk::render(RenderDevice* rd, const Lighting& lighting, bool caps, float lod)
{
    do {} while (0);
    if (lighting != lastLighting) {
        lastLighting = lighting;
        indices.fastClear();
        shortIndices.fastClear();
        if (owner->hidden())
            return;
        static Array<Vec3> vertices;
        vertices.fastClear();
        vertices.append(-lighting.lightDirection().direction() * lod);
        do {} while (0);
        Vec3 lightDir = lighting.lightDirection().direction();
        builder->build(frame(), lightDir, indices, vertices, caps);
        if (vertices.size() < 0x10000) {
            int n = indices.size();
            shortIndices.resize(n);
            for (int i = 0; i < n; ++i)
                shortIndices[i] = indices[i];
            indices.fastClear();
        }
        Ref<VARArea> area = VARArea::create(vertices.size() * 12, 1);
        vertexArray = VAR(vertices, area);
    }
    if (indices.size() > 0) {
        rd->beginIndexedPrimitives();
        rd->setVertexArray(vertexArray);
        rd->sendIndices(2, indices);
        rd->endIndexedPrimitives();
    } else if (shortIndices.size() > 0) {
        rd->beginIndexedPrimitives();
        rd->setVertexArray(vertexArray);
        rd->sendIndices(2, shortIndices);
        rd->endIndexedPrimitives();
    }
}
