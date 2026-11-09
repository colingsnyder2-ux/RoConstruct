// from server: 97% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)
#pragma float_control(precise, off)

struct Vector3 {
    float x, y, z;
    Vector3();
    Vector3(float, float, float);
};
__forceinline Vector3::Vector3() {}
__forceinline Vector3::Vector3(float a, float b, float c) : x(a), y(b), z(c) {}

struct VectorArray {
    void clear(bool, bool);
    void append(const Vector3&);
};
struct OtherArray {
    void clear(bool, bool);
};
struct Light {
    const Vector3& direction(Vector3&) const;
};
struct Entry;
struct Processor {
    void process(Entry*, const Vector3&, OtherArray&, VectorArray&, bool);
};
struct Entry {
    unsigned char storage[0x40];
    Processor* processor;
};
struct Scene {
    unsigned char padding[0x58];
    Entry* entries;
    int count;
    void render(OtherArray&, VectorArray&, const Light&, bool, float) const;
};

void Scene::render(OtherArray& other, VectorArray& vectors,
                   const Light& light, bool flag, float distance) const
{
    vectors.clear(false, false);
    other.clear(false, false);
    Vector3 temporary;
    {
        const Vector3& direction = light.direction(temporary);
        float inverseLength = (float)(1.0 / sqrt(
            direction.x * direction.x +
            direction.y * direction.y +
            direction.z * direction.z));
        Vector3 normalized(direction.x * inverseLength,
                           direction.y * inverseLength,
                           direction.z * inverseLength);
        Vector3 negative(-normalized.x, -normalized.y, -normalized.z);
        Vector3 displacement(negative.x * distance,
                             negative.y * distance,
                             negative.z * distance);
        vectors.append(displacement);
    }
    const Vector3& direction = light.direction(temporary);
    double inverseLength = 1.0 / sqrt(
        direction.x * direction.x +
        direction.y * direction.y +
        direction.z * direction.z);
    Vector3 unitDirection(direction.x * inverseLength,
                          direction.y * inverseLength,
                          direction.z * inverseLength);
    for (int i = 0; i < count; ++i) {
        Entry* entry = entries + i;
        entry->processor->process(entry, unitDirection, other, vectors, flag);
    }
}
