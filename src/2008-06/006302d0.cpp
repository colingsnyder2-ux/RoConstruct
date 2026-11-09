// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_linearvec_4548c7edf448edad.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#pragma float_control(precise, off)

struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec& operator=(const Vec& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
    Vec operator-(const Vec& v) const {
        return Vec(x - v.x, y - v.y, z - v.z);
    }
    Vec operator-() const {
        return Vec(-x, -y, -z);
    }
    Vec operator*(float s) const {
        return Vec(x * s, y * s, z * s);
    }
    Vec* clamp(Vec* result, const Vec* lower, const Vec* upper);
};

struct Body;

struct Object {
    char padding[0x2c8];
    Body* body;
};

typedef boost::shared_ptr<Object> Shared;

struct Handle {
    char storage[8];
    Shared get();
};

struct Accumulator {
    char padding0[8];
    unsigned char dirty;
    char padding1[0x7b];
    Vec torque;
    void update();
};

struct Parent {
    char padding[0x2c];
    Accumulator* accumulator;
};

struct MassSource {
    float getMass();
};

struct Node {
    char padding0[0x10];
    Parent* parent;
    char padding1[0x14];
    MassSource* massSource;
    char padding2[0x60];
    float mass;
};

struct Body {
    char padding0[0x10];
    Node* node;
    char padding1[0xb0];
    Vec angularVelocity;
    const void* get();
};

struct S {
    char padding[0x10];
    Handle handle;
    float gain;
    Vec limit;
    Vec desired;
    Vec torque;
    void f(float, float);
};

void S::f(float, float)
{
    Body* body = handle.get()->body;

    body->get();
    {
        Vec difference = (desired - body->angularVelocity) * gain;
        Node* node = body->node;
        torque = difference * (node->massSource
            ? node->massSource->getMass() : node->mass);
    }
    {
        Vec lower = -limit;
        Vec result;
        torque = *torque.clamp(&result, &lower, &limit);
    }

    Accumulator* accumulator = body->node->parent->accumulator;
    if (accumulator) {
        if (accumulator->dirty)
            accumulator->update();
        Vec& applied = torque;
        accumulator->torque.x = accumulator->torque.x + applied.x;
        accumulator->torque.y = applied.y + accumulator->torque.y;
        accumulator->torque.z = applied.z + accumulator->torque.z;
    }
}
