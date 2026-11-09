// from server: 100% by king_originala
#pragma float_control(precise, off)

extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)

struct Event {
    char padding[8];
    short x;
    short y;
};

struct Vector2 {
    float x, y;
    Vector2(float, float);
    Vector2 operator-(const Vector2&) const;
};

inline Vector2::Vector2(float a, float b) : x(a), y(b) {}

inline Vector2 Vector2::operator-(const Vector2& other) const
{
    return Vector2(x - other.x, y - other.y);
}

struct Vector3 {
    float x, y, z;
};

struct Controller {
    void begin();
    void update();
    Vector3* position(Vector3*, const Event*);
};

struct S {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void dispatch(const Event*) = 0;

    char padding[24];
    Controller* controller;
    Vector2 start;
    bool dragging;
    Vector3 dragPosition;

    void f(const Event*);
};

void S::f(const Event* event)
{
    if (!dragging) {
        Vector2 delta = Vector2((float)event->x, (float)event->y) - start;
        float distance = (float)sqrt(delta.x * delta.x + delta.y * delta.y);
        if (distance > *(const float*)0x00826e6c) {
            dragging = true;
            controller->begin();
            controller->update();
            Vector3 temporary;
            const Vector3* position = controller->position(&temporary, event);
            dragPosition.x = position->x;
            dragPosition.y = position->y;
            dragPosition.z = position->z;
        }
    }
    dispatch(event);
}
