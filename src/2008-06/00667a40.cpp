// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_jumpcomparison_6b4b2fffa050f82d.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise, off, push)

struct Vector3 {
    float x, y, z;
};

__forceinline const float& minimum(const float& a, const float& b)
{
    return b < a ? b : a;
}

struct ForceReceiver {
    void apply(const Vector3*, const Vector3*);
};

struct BodyLink {
    char reserved[0x2c];
    ForceReceiver* receiver;
};

struct MassSource {
    float getMass();
};

struct Body {
    char reserved0[0x10];
    BodyLink* link;
    char reserved1[0x14];
    MassSource* massSource;
    char reserved2[0x60];
    float mass;
    char reserved3[0x38];
    float height;

    const void* get();
    const Vector3* getVelocity();
    void apply(const Vector3*);
};

struct Owner {
    Body* getBody();
};

struct BodyHolder {
    char reserved[0x10];
    Body* body;
};

struct Character {
    char reserved[0xa0];
    BodyHolder* holder;
};

extern const float jumpScale;
extern const float jumpHeight;

struct Jumping {
    char reserved0[0x11];
    unsigned char finished;
    char reserved1[0x1a];
    Vector3 position;

    void baseUpdate(float);
    Owner* getOwner();
    Character* getCharacter();
    void update(float);
};

void Jumping::update(float dt)
{
    baseUpdate(dt);
    if (finished)
        return;

    Body* body = getOwner()->getBody();
    float amount;
    if (!body)
        goto finish;

    body->get();
    amount = (jumpHeight - body->height) * jumpScale;
    if (amount <= 0.0f) {
finish:
        finished = 1;
        return;
    }

    if (!getCharacter())
        return;

    Body* other = getCharacter()->holder->body;
    dt = other->massSource
        ? other->massSource->getMass()
        : other->mass;

    float mass = body->massSource
        ? body->massSource->getMass()
        : body->mass;
    dt = minimum(mass, dt) * amount;

    const float& vertical = body->getVelocity()->y;
    if (dt > vertical) {
        dt -= vertical;
        Vector3 force;
        force.x = 0.0f;
        force.y = dt;
        force.z = 0.0f;
        body->apply(&force);

        ForceReceiver* receiver = other->link->receiver;
        force.x = 0.0f;
        force.y = -dt;
        force.z = 0.0f;
        if (receiver)
            receiver->apply(&force, &position);
    }
}

#pragma float_control(pop)
