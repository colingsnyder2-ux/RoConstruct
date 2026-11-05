// from server: 39% by colin
struct Vec3 {
    float x, y, z;
};

struct World {
    char pad0[0x1c];
    void* something;
};

struct Body {
    char pad0[0x04];
    Body* next;
    char pad8[0x14];
    int hasSpring;
    char pad20[0x5c];
    void* joint;
    char pad80[0x28];
    Vec3 pos;
    Vec3 vel;
    char padB4[0x04];
    Vec3 rot;
    char padC4[0x04];
    float springK;
    float springD;
    float springTarget;
    World* world;
};

struct Part {
    char pad0[0x04];
    World* world;
    char pad8[0x5c];
    Body* body;
};

struct Instance {
    char pad0[0x10];
    Part* part;
};

struct BodyPosition {
    char pad0[0x14];
    Vec3 target;
    char pad20[0x14];
    Vec3 force;
    char pad40[0x24];
    Instance* instance;

    void step(float dt, int param);
};

extern "C" void __stdcall sub_530100(void* p);
extern "C" float __stdcall sub_624D80(void* p);
extern "C" void __stdcall sub_4A04A0(Vec3* out, Vec3* a, Vec3* b);
extern "C" void __stdcall sub_5CF030(Vec3* a, Vec3* b);

void BodyPosition::step(float dt, int param)
{
    Instance* inst = this->instance;
    Body* body = inst->part->body;
    Body* b2 = body->next;

    sub_530100(body);

    Vec3 delta;
    delta.x = this->target.x - body->pos.x;
    delta.y = this->target.y - body->pos.y;
    delta.z = this->target.z - body->pos.z;

    float scale = this->force.x;
    delta.x *= scale;
    delta.y *= scale;
    delta.z *= scale;

    sub_530100(body);

    float neg = -this->force.y;
    float rx = body->rot.x * neg;
    float ry = body->rot.y * neg;
    float rz = body->rot.z * neg;

    Vec3 accel;
    accel.x = delta.x + rx;
    accel.y = delta.y + ry;
    accel.z = delta.z + rz;

    float mass;
    if (b2->world->something == 0) {
        mass = sub_624D80(b2->world->something);
    } else {
        mass = b2->springK;
    }

    Vec3 out;
    out.x = accel.x * mass;
    out.y = accel.y * mass;
    out.z = accel.z * mass;

    Vec3 negForce;
    negForce.x = -this->force.x;
    negForce.y = -this->force.y;
    negForce.z = -this->force.z;

    Vec3 result;
    sub_4A04A0(&result, &negForce, &out);

    this->force.x = result.x;
    this->force.y = result.y;
    this->force.z = result.z;

    Body* b3 = body->next;
    sub_530100(b3);

    if (b3->next->joint != 0) {
        sub_5CF030(&this->force, (Vec3*)((char*)b3 + 0xa8));
    }
}
