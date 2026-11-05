// from server: 100% by EspClaude
// from server: 99% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_c72a6fc53d306842.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise, off)
#include <G3D/Vector3.h>



extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" __declspec(dllimport) int __cdecl rand();
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();
extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)

extern const float randomScale;
extern const float delayOffset;
extern const float initialDistance;
extern const char instanceType[];
extern const char pvInstanceType[];

struct Object;
struct Container;

struct RefCount
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<Object> Shared;

#include <boost/weak_ptr.hpp>
typedef boost::weak_ptr<Object> Weak;

struct __declspec(align(8)) Transform
{
    float rotation[9];
    G3D::Vector3 position;
};

struct TransformInterface
{
    virtual Transform getTransform() = 0;
};

struct Identity
{
    virtual void unused0() = 0;
    virtual void unused1() = 0;
    virtual void* getIdentity() = 0;
};

struct Object
{
    char padding[0x134];
    int* virtualOffsets;
    Container* getContainer();
    bool eligible();
    Identity* identity();
};

struct Children
{
    char padding[12];
    Shared* first;
    Shared* last;
};

struct Container
{
    char padding[0x108];
    Children* children;
    unsigned size();
};

extern "C" void* __cdecl dynamicCastHelper(
    void*, long, const void*, const void*, int);
extern Shared __cdecl makeShared(Object*);

struct Controller
{
    char padding0[0x18];
    Weak source;
    float nextTime;
    char padding1[0x38];
    Shared selected;
    void update(void*, float);
};

#pragma float_control(precise, off, push)

void Controller::update(void* excluded, float time)
{
    if (time < nextTime)
        return;

    nextTime = (rand() * randomScale + time) + delayOffset;
    Shared current = source.lock();
    if (!current)
        return;
    Object* object = current.get();

    Container* container = object->getContainer();
    if (!container)
        return;

    float closest = initialDistance;
    TransformInterface* transform = reinterpret_cast<TransformInterface*>(
        reinterpret_cast<char*>(object) + 0x134 + object->virtualOffsets[2]);
    Transform origin = transform->getTransform();

    for (unsigned i = 0; i < container->size(); ++i)
    {
        Children* children = container->children;
        if (i >= static_cast<unsigned>(children->last - children->first))
            _invalid_parameter_noinfo();

        Shared* element = &children->first[i];
        Object* candidate = static_cast<Object*>(dynamicCastHelper(
            element->get(), 0, instanceType, pvInstanceType, 0));

        if (!candidate || candidate == current.get() ||
            !candidate->eligible() ||
            candidate->identity()->getIdentity() == excluded)
            continue;

        TransformInterface* candidateTransform =
            reinterpret_cast<TransformInterface*>(
                reinterpret_cast<char*>(candidate) + 0x134 +
                candidate->virtualOffsets[2]);
        double distance = (candidateTransform->getTransform().position - origin.position).magnitude();

        if (closest > distance)
        {
            closest = static_cast<float>(distance);
            selected = makeShared(candidate);
        }
    }
}

#pragma float_control(pop)
