// from server: 100% by EspClaude
// from server: 98% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_082fafcb387d2616.cpp

// Candidate translation unit (score above; library headers required).

#pragma float_control(precise, off)

#include "G3D/Vector3.h"
typedef G3D::Vector3 Vec3;

struct Body
{
    char pad0[8];
    unsigned char dirty;
    char pad1[0x9f];
    Vec3 accumulated;
    void update();
    void addForce(Vec3 f) { if (dirty) update(); accumulated += f; }
    void apply(const Vec3*, const Vec3*);
};

struct Link
{
    char pad[0x2c];
    Body* body;
};

struct Attachment
{
    char pad[0x10];
    Link* link;
};

struct Transform
{
    char pad[0x24];
    Vec3 position;
};

struct PartInstance
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual float size();
    char pad[0x9c];
    Attachment* attachment;
    Transform* transform();
    void detach();
};

struct GetSetImpl
{
    static PartInstance* get(PartInstance*);
};

struct Context
{
    void reset();
    void insert(PartInstance*, int);
};

struct Parts
{
    PartInstance** data;
    int count;
};

struct Explosion
{
    char pad[0x148];
    Vec3 position;
    float radius;
    float pressure;
    void explode(Parts*);
};

extern Context* __cdecl getContext(Explosion*);
extern bool __cdecl isProtected(PartInstance*);
extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)

extern float zeroX, zeroY, zeroZ;
extern unsigned int zeroInitialized;
extern Vec3 upVector;
extern unsigned int upInitialized;
extern const float forceScale;
extern const float secondaryScale;

void Explosion::explode(Parts* parts)
{
    if (pressure > 0.0f)
    {
        Context* context = getContext(this);
        for (int i = 0; i < parts->count; ++i)
        {
            PartInstance* part = parts->data[i];
            float limit = radius + radius;
            if (part->size() < limit)
            {
                PartInstance* instance = GetSetImpl::get(part);
                if (!isProtected(instance))
                    instance->detach();
            }
        }

        context->reset();

        for (int i = 0; i < parts->count; ++i)
        {
            PartInstance* part = parts->data[i];
            float limit = radius + radius;
            if (part->size() < limit)
            {
                Vec3 delta(0,0,0);
                context->insert(part, 1);
                delta = part->transform()->position - position;

                Vec3 unit = delta == Vec3::zero() ? Vec3::unitY() : delta.direction();
                float size = part->size();
                Vec3 impulse(0,0,0);
                Attachment* attachment = part->attachment;
                float square = size * size;
                Vec3 force = ((unit * pressure) * square) * forceScale;

                const Vec3* point = &part->transform()->position;
                Body* body = attachment->link->body;
                if (body)
                    body->apply(&force, point);

                Body* secondary = part->attachment->link->body;
                impulse = (force * secondaryScale) * size;
                if (secondary)
                {
                    secondary->addForce(impulse);
                }
            }
        }
    }
}
