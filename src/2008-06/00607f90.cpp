// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

struct Geometry {
    char pad[0x10];
    Vector3* vertices;
};

struct Object {
    char pad[0x9c];
    Geometry* geometry;
    void* data;
};

struct Contact {
    char pad0[8];
    int type;
    Vector3* first;
    Vector3* second;
    char pad1[0x10];
    int secondIndex;
    int firstIndex;
};

struct S {
    char pad[0x0c];
    Object* objects[2];

    Contact* create(void*, void*, int, int, int);
    Contact* f(int, int, int, int, int);
};

Contact* S::f(int firstObject, int secondObject, int firstIndex,
              int faceIndex, int secondIndex)
{
    Object* secondObjectPtr = objects[secondObject];
    Object* firstObjectPtr = objects[firstObject];
    void* secondData = secondObjectPtr->data;
    void* firstData = firstObjectPtr->data;
    Contact* result = create(firstData, secondData, 4, firstIndex, secondIndex);

    int (*vertexIndices)[4] = reinterpret_cast<int (*)[4]>(0x84aec8);
    int offset = vertexIndices[secondIndex][0] * 3;
    Vector3* second = reinterpret_cast<Vector3*>(
        reinterpret_cast<float*>(objects[secondObject]->geometry->vertices)
        + offset);
    Vector3* first = objects[firstObject]->geometry->vertices
                   + vertexIndices[faceIndex][firstIndex];

    result->secondIndex = secondIndex;
    result->firstIndex = firstIndex;
    result->first = first;
    result->second = second;
    result->type = 4;
    return result;
}
