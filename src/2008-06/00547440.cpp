// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Local names were chosen to reproduce the /Od frame layout (MSVC orders locals by name hash).
// Analog for 00547440: world-space bounds of every chunk's level-0 vertices
// (G3D Vector3 inf/min/max, CoordinateFrame::pointToWorldSpace, handleFor 00548f80).
class Vec3 {
public:
    static const Vec3& inf();
    Vec3 operator-() const;
    Vec3 min(const Vec3& other) const;
    Vec3 max(const Vec3& other) const;
    Vec3& operator=(const Vec3& other);
    float x, y, z;
};

class CFrame {
public:
    Vec3 pointToWorldSpace(const Vec3& v) const;
};

template<class T>
class Array {
public:
    int size() const;
    T& operator[](int n);
    T* data;
    int num;
    int numAllocated;
};

template<class T>
class Ref {
public:
    ~Ref();
    T* operator->() const;
    bool isNull() const;
    T* pointer;
};

class LevelData {
public:
    char header[0x0c];
    Array<int> indices;
};

class Levels {
public:
    Ref<LevelData> handleFor(float distance);
};

class Chunk {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Ref<Levels> part();
    virtual const CFrame& frame();
};

class Iter {
public:
    bool operator!=(const Iter& other) const;
    Iter& operator++();
    const Ref<Chunk>& operator*() const;
    void* node;
    void* owner;
};

class Chunks {
public:
    Iter begin() const;
    Iter end() const;
};

extern Array<Vec3> slotFirst;

void computeBounds(const Chunks& chunks, Vec3& low, Vec3& high)
{
    low = Vec3::inf();
    high = -Vec3::inf();
    Iter end = chunks.end();
    for (Iter it = chunks.begin(); it != end; ++it) {
        const Ref<Chunk>& chunk = *it;
        const Ref<Levels>& v395 = chunk->part();
        if (v395.isNull())
            continue;
        const CFrame& frame = chunk->frame();
        Ref<LevelData> v343 = v395->handleFor(0.0f);
        Array<int>& v345 = v343->indices;
        for (int v391 = 0; v391 < v345.size(); ++v391) {
            int index = v345[v391];
            Vec3 v = frame.pointToWorldSpace(slotFirst[index]);
            high = high.max(v);
            low = low.min(v);
        }
    }
}
