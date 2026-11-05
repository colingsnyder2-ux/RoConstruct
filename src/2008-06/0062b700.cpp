// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_explosionsteppedevent_63ada37d19f46ecd.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <G3D/AABox.h>
#include <G3D/Array.h>
extern const float threshold;
extern "C" void __cdecl alignedFree(void *);

struct Array {
    void *data;
    int capacity;
    int size;
    Array();
    ~Array();
};

inline Array::Array()
{
    capacity = 0;
    size = 0;
    data = 0;
}

inline Array::~Array()
{
    alignedFree(data);
}

typedef G3D::AABox Box;
struct Query {
    void collect(const Box &, int, Array &);
};

struct Object {
    void first(Array &);
    void second(Array &);
    void detach(int);
};

struct World {
    char padding[0x84];
    Query *query;
};

extern World *__cdecl getWorld(Object *);

struct Stepped{const float time;const float step;Stepped(float t,float s):time(t),step(s){}};
struct Explosion {
    char padding[0x14];
    float elapsed;
    float x, y, z;
    float radius;
    void update(void*, Stepped);
};

void Explosion::update(void*, Stepped event)
{
    elapsed += event.step;
    if (elapsed > threshold) {
        if (radius > 0.0f) {
            Array results;
            Object *object = reinterpret_cast<Object *>(
                reinterpret_cast<char *>(this) - 0x130);
            World *world = getWorld(object);
            const float r = radius;
            Box box(G3D::Vector3(x-r,y-r,z-r),G3D::Vector3(x+r,y+r,z+r));
            Query *q = world->query;
            q->collect(box, 0, results);
            object->first(results);
            object->second(results);
        }
        reinterpret_cast<Object *>(
            reinterpret_cast<char *>(this) - 0x130)->detach(0);
    }
}
