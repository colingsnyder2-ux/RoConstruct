// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_lasertool_a73b1193b03a933d.cpp

// Candidate translation unit (score above; library headers required).


extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad[0x100];
    Instance* next;
};
class ServiceProvider : public Instance {
public:
    ServiceProvider* finish();
    void setState(int);
};
}

struct Vector3 {
    float x, y, z;
};

struct Transform {
    char pad[0x24];
    Vector3 position;
};

struct Source {
    Transform* getTransform();
};

struct Object {
    char pad[0x14];
    void attach(RBX::Instance*);
};

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<Object> Handle;

struct VectorProperty {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, const Vector3*);
};

struct FloatProperty {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, const float*);
};

struct Hit {
    char pad[0x1f0];
    unsigned char active;
    void activate();
};

extern VectorProperty* vectorProperty;
extern FloatProperty* floatProperty;

Source* __cdecl findSource(RBX::Instance*);
Handle __cdecl makeHandle();
RBX::ServiceProvider* __cdecl func_005807b0(RBX::Instance*);

struct S {
    char pad[0x18];
    RBX::Instance* instance;
    int state;
    Vector3 position;

    Hit* findHit(void*, int, Vector3*);
    S* f(void*);
};

S* S::f(void* argument) {
    Source* source = findSource(instance);
    if (source) {
        const Vector3& origin = source->getTransform()->position;
        position.x = origin.x;
        position.y = origin.y;
        position.z = origin.z;

        Vector3 point;
        point.x = 0.0f;
        point.y = 0.0f;
        point.z = 0.0f;

        Hit* hit = findHit(argument, 0, &point);
        if (hit) {
            Handle handle = makeHandle();

            vectorProperty->set(
                handle.get() ? reinterpret_cast<char*>(handle.get()) + 0x14 : 0,
                &point);

            float value = 0.0f;
            floatProperty->set(
                handle.get() ? reinterpret_cast<char*>(handle.get()) + 0x14 : 0,
                &value);

            handle.get()->attach(instance);
            if (!hit->active)
                hit->activate();

            func_005807b0(instance)->setState(9);
        }
        state = 4;
    }
    return this;
}