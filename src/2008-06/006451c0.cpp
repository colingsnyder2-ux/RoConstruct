// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
    Vector3& operator=(const Vector3&);
};

inline Vector3& Vector3::operator=(const Vector3& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

struct Matrix3 {
    float values[9];
};

struct Transform {
    Matrix3 rotation;
    Vector3 translation;
    Transform& operator=(const Transform&);
};

inline Transform& Transform::operator=(const Transform& other)
{
    rotation = other.rotation;
    translation.x = other.translation.x;
    translation.y = other.translation.y;
    translation.z = other.translation.z;
    return *this;
}

struct Primitive {
    const Vector3& getValue();
};

struct Part {
    char padding[0x228];
    Primitive primitive;
};

struct PartReference {
    Part* pointer;
    void* control;
    void reset();
};

struct Controller {
    void setPrimitive(Primitive*, int);
};

struct Owner {
    char padding[0x21c];
    Controller* controller;
};

struct StateColumn {
    int value;
    char padding[68];
};

extern StateColumn stateFirst[];
extern StateColumn stateSecond[];
extern StateColumn stateThird[];
extern StateColumn stateFourth[];
extern const Vector3& __cdecl zeroVector();

struct Climbing {
    virtual void slot0();
    virtual void slot1();
    virtual int state();
    virtual bool firstFlag();
    virtual bool secondFlag();
    virtual bool thirdFlag();

    int reserved;
    Owner* owner;
    float remaining;
    char padding10[0x10];
    bool active;
    char padding21[3];
    PartReference part;
    Vector3 velocity;
    char padding38[8];
    Transform previous;
    Transform current;

    void update(float);
    void setFirst(bool);
    void setSecond(bool);
    void setThird(bool);
    void refreshPart();
    bool check(int);
};

void Climbing::update(float dt)
{
    Part* oldPart = part.pointer;
    active = false;
    part.reset();

    velocity = zeroVector();

    remaining -= dt;
    setFirst(firstFlag());
    setSecond(secondFlag());
    setThird(thirdFlag());

    if (stateThird[state()].value != 13 ||
        stateFourth[state()].value != 13) {
        refreshPart();
        if (part.pointer) {
            Primitive* selected =
                part.pointer ? &part.pointer->primitive : 0;
            owner->controller->setPrimitive(selected, 0);
            if (oldPart == part.pointer) {
                previous = current;
                Primitive* primitive =
                    part.pointer ? &part.pointer->primitive : 0;
                current = reinterpret_cast<const Transform&>(
                    primitive->getValue());
            } else {
                Primitive* primitive =
                    part.pointer ? &part.pointer->primitive : 0;
                previous = reinterpret_cast<const Transform&>(
                    primitive->getValue());
                primitive = part.pointer ? &part.pointer->primitive : 0;
                current = reinterpret_cast<const Transform&>(
                    primitive->getValue());
            }
        }
    }

    if (stateFirst[state()].value != 13 ||
        stateSecond[state()].value != 13)
        active = check(0);
}
