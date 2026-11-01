// from server: 100% by colin
struct Result;

struct Vector3 {
    float x, y, z;
};

extern const float scale;
extern "C" void __cdecl buildResult(Result*, const Vector3*);

struct S {
    char pad[16];
    float size;
    Result* f(Result* result, float mass);
};

#pragma float_control(precise, off, push)

Result* S::f(Result* result, float mass)
{
    Vector3 diagonal;
    diagonal.z = diagonal.y = diagonal.x = scale * (mass * (size * size));
    buildResult(result, &diagonal);
    return result;
}

#pragma float_control(pop)
