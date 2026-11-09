// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// Analog for 00548c60: stores the reserved slot's position (operator[] 00518b80,
// assignment 00514be0), then either runs the shared initializer (00548cb0) or
// uploads the value to the vertex program (005513d0).
class Vec3 {
public:
    Vec3& operator=(const Vec3& other);
    float x, y, z;
};

template<class T>
class Array {
public:
    T& operator[](int n);
    T* data;
    int num;
    int numAllocated;
};

class Program {
public:
    void setVector(int index, const Vec3& value);
    void* pointer;
};

extern bool sharedDisabled;
extern Array<Vec3> slotFirst;
extern Program vertexProgram;
void initializeShared();

void setOrigin(const Vec3& origin)
{
    do {} while (0);
    slotFirst[0] = origin;
    if (sharedDisabled)
        initializeShared();
    else
        vertexProgram.setVector(0, origin);
}
