// from server: 100% by king_originala
#pragma float_control(precise, off)

struct Vector3 {
    float x, y, z;
};

struct Matrix3 {
    float m[9];
    Matrix3(const Matrix3&);
};

struct Frame {
    Matrix3 rotation;
    Vector3 translation;
};

struct Work {
    Vector3 midpoint;
    Vector3 difference;
    Vector3 first;
    Vector3 second;
};

extern const Vector3& __cdecl position();
extern const Matrix3& __cdecl identity();
extern const Vector3& __cdecl axis();

struct Controller {
    virtual void slot0();
    virtual void slot1();
    virtual void* transform();
};

extern void __cdecl apply(Vector3*, const Frame*, void*, void*, const Vector3&);

struct Owner {
    char padding[0x288];
    Controller controller;
};

struct Base {
    bool adjust(Vector3&);
};

struct Tool {
    char padding[0x14];
    Owner* owner;
    void update(void*);
};

void Tool::update(void* argument)
{
    Work w;

    const Vector3& a = position();
    w.first.x = a.x;
    w.first.y = a.y;
    w.first.z = a.z;

    const Vector3& b = position();
    w.second.x = -b.x;
    w.second.y = -b.y;
    w.second.z = -b.z;

    if (reinterpret_cast<Base*>(reinterpret_cast<char*>(this) - 4)->adjust(w.first)) {
        Vector3 sum = {
            w.second.x + w.first.x,
            w.second.y + w.first.y,
            w.second.z + w.first.z
        };

        w.midpoint.x = sum.x * 0.5f;
        w.midpoint.y = sum.y * 0.5f;
        w.midpoint.z = sum.z * 0.5f;

        Frame frame = {
            identity(),
            { w.midpoint.x, w.midpoint.y, w.midpoint.z }
        };

        Controller* controller = &owner->controller;

        w.difference.x = w.second.x - w.first.x;
        w.difference.y = w.second.y - w.first.y;
        w.difference.z = w.second.z - w.first.z;

        apply(&w.difference, &frame, controller->transform(), argument, axis());
    }
}
