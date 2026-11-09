// from server: 50% by tester
struct Vector3 {
    float x, y, z;
};

struct BodyVelocity {
    char pad0[0x10];
    void* part;
    float kP;
    Vector3 velocity;
    Vector3 maxForce;
    Vector3 force;

    void computeForce(float dt, void* world);
};

extern "C" void __stdcall sub_530100(void* p);
extern "C" float __stdcall sub_624d80(void* p);
extern "C" Vector3* __stdcall sub_4a04a0(Vector3* out, Vector3* a, Vector3* b);
extern "C" void __stdcall sub_5cf030(Vector3* out, Vector3* in);

void BodyVelocity::computeForce(float dt, void* world)
{
    void* p = *(void**)((char*)part + 0x1d8);
    void* q = *(void**)((char*)p + 0x64);
    sub_530100(q);

    float dx = velocity.x - *(float*)((char*)q + 0xb4);
    float dy = velocity.y - *(float*)((char*)q + 0xb8);
    float dz = velocity.z - *(float*)((char*)q + 0xbc);

    float k = kP;
    dx *= k;
    dy *= k;
    dz *= k;

    void* r = *(void**)((char*)q + 4);
    void* s = *(void**)((char*)r + 0x1c);
    float mass;
    if (s != 0) {
        mass = sub_624d80(s);
    } else {
        mass = *(float*)((char*)r + 0x7c);
    }

    force.x = dx * mass;
    force.y = dy * mass;
    force.z = dz * mass;

    Vector3 negVel;
    negVel.x = -velocity.x;
    negVel.y = -velocity.y;
    negVel.z = -velocity.z;

    Vector3* result = sub_4a04a0(&negVel, &velocity, &maxForce);
    force.x = result->x;
    force.y = result->y;
    force.z = result->z;

    void* j2 = *(void**)((char*)q + 4);
    sub_530100(j2);
    void* w2 = *(void**)((char*)j2 + 4);
    void* s2 = *(void**)((char*)w2 + 0x20);
    if (s2 != 0) {
        sub_5cf030(&force, (Vector3*)((char*)j2 + 0xa8));
    }
}
