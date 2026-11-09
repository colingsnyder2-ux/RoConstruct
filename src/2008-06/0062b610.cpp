// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_explosionhitnative004fd2267e539f66.cpp

// Candidate translation unit (score above; library headers required).

extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)
#pragma float_control(precise, off)

#include "G3D/Vector3.h"
#include <boost/shared_ptr.hpp>
typedef G3D::Vector3 Vector3;
struct Frame
{
    char padding[36];
    Vector3 position;
};

struct Primitive
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual float measure();
    const Frame& getValue();
};

struct PartInstance;

struct GetSetImpl
{
    static PartInstance* get(Primitive*);
};

typedef boost::shared_ptr<PartInstance> Pair;

Pair __cdecl makePair(PartInstance*);

struct Proxy
{
    bool empty();
};

struct Connection
{
    char padding[16];
    Proxy* proxy;
};

struct Base
{
    char padding[0x134];
};

struct Signal
{
    Connection* find(Base*);
    void fire(Base*, Pair, float);
};

extern Signal signal;

struct Head
{
    char padding[20];
};

struct List
{
    Primitive** data;
    int count;
};

struct S : Head, Base
{
    Vector3 position;
    float radius;
    void process(List*);
};

void S::process(List* list)
{
    Connection* connection = signal.find(this);
    if (!connection || connection->proxy->empty())
        return;

    for (int i = 0; i < list->count; ++i)
    {
        Primitive* primitive = list->data[i];
        float diameter = radius + radius;
        if (diameter > primitive->measure())
        {
            PartInstance* part = GetSetImpl::get(primitive);
            if (part)
            {
                float distance = (primitive->getValue().position-position).magnitude();
                signal.fire(this, makePair(part),distance);
            }
        }
    }
}