// from server: 100% by king_originala
struct Vector
{
    float x, y, z;
    Vector(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct Matrix
{
    float values[9];
};

struct Camera
{
    Matrix* rotation(Matrix* result) const;
};

struct Body
{
    char padding[0x94];
    Camera camera;

    const void* get();
};

struct Owner
{
    int f();
};

struct S
{
    char padding[8];
    Owner* owner;

    double f();
};

double S::f()
{
    Body* body = (Body*)owner->f();
    if (body)
    {
        static Vector up(0.0f, 1.0f, 0.0f);

        body->get();
        Matrix storage;
        Matrix* rotation = body->camera.rotation(&storage);
        return rotation->values[4] * up.y
             + rotation->values[5] * up.z
             + rotation->values[3] * up.x;
    }
    return 1.0;
}
