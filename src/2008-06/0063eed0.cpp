// from server: 48% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
#pragma float_control(precise, off)

extern "C" double __cdecl floor(double);
#pragma intrinsic(floor)

struct Vector
{
    float x, y, z;
};

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* object;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
{
    if (control)
    {
        if (_InterlockedExchangeAdd(&control->strong, -1) == 0)
        {
            control->dispose();
            if (_InterlockedExchangeAdd(&control->weak, -1) == 0)
                control->destroy();
        }
    }
}

struct Ray
{
    void* table;
    Vector origin;
    Vector direction;
    ~Ray();
};

inline Ray::~Ray()
{
}

struct Transform
{
    char data[72];
    ~Transform();
};

inline Transform::~Transform()
{
}

struct Input
{
    Vector direction;
    float scale;
    Control* control;
};

extern "C" void __cdecl makeRay(Ray*, const Vector*, const Vector*);
extern "C" void __cdecl transformPoint(Vector*, const Ray*, const Transform*);
extern float negativeLimit;

struct S
{
    char padding[0x30];
    Vector origin;
    char gap[4];
    int accumulated;

    void* getTransform(void*, void*);
    void resize(int);
    void f(void*);
};

void S::f(void* input)
{
    Vector direction;
    {
        Input* p = static_cast<Input*>(input);
        Shared shared;
        shared.object = input;
        shared.control = p->control;
        float scale = p->scale;
        direction.x = p->direction.x * scale;
        direction.y = p->direction.y * scale;
        direction.z = p->direction.z * scale;
    }

    Ray ray;
    makeRay(&ray, &origin, &direction);

    Transform transform;
    getTransform(&transform, input);

    Vector point;
    transformPoint(&point, &ray, &transform);

    Vector difference = {
        point.x - origin.x,
        point.y - origin.y,
        point.z - origin.z
    };

    float delta = difference.y * ray.direction.y
                + difference.z * ray.direction.z
                + difference.x * ray.direction.x
                - accumulated;

    if (delta > 1.0f)
    {
        float rounded = static_cast<float>(floor(delta));
        int amount = static_cast<int>(rounded);
        accumulated += amount;
        resize(amount);
    }

    if (delta < negativeLimit)
    {
        float rounded = static_cast<float>(floor(-delta));
        int amount = -static_cast<int>(rounded);
        accumulated += amount;
        resize(amount);
    }
}
