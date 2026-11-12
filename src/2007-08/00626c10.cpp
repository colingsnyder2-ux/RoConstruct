// from server: 100% by EspClaude
// from server: 75% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-lib: openrbx-client-dll roc_claude_4ce3c4987ac7c84c.cpp

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
    char reserved[0x20];
    ForceReceiver* receiver;
};

struct MassSource {
    float getMass();
};

struct Body {
    char reserved0[4];
    BodyLink* link;
    char reserved1[0x14];
    MassSource* massSource;
    char reserved2[0x5c];
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
    char reserved[4];
    Body* body;
};

struct HolderLink {
    char reserved[0x64];
    BodyHolder* holder;
};

struct Character {
    char reserved[0x1d8];
    HolderLink* link;
};

extern const float jumpScale;
extern const float jumpHeight;

struct Jumping {
    char reserved0[4];
    Owner* owner;
    char reserved1[0xc];
    Character* character;
    char reserved2[4];
    Vector3 position;
    char reserved3[4];
    unsigned char finished;
    float timer;

    void baseUpdate(float);
    void update(float);
};

void Jumping::update(float dt)
{
    baseUpdate(dt);
    timer -= dt;
    if (finished)
        return;

    Body* body = owner->getBody();
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

    if (!character)
        return;

    Body* other = character->link->holder->body;
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
