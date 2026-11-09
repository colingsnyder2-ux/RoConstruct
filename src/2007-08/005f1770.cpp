// from server: 67% by tajop
struct Matrix3 {
    float elt[9];
    Matrix3(const Matrix3& m);
};

struct Vector3 {
    float x, y, z;
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct CoordinateFrame {
    Matrix3 rotation;
    Vector3 translation;
};

struct bad_function_call {
    int data[10];
    bad_function_call();
    ~bad_function_call();
};

__declspec(noreturn) void throw_exception(const bad_function_call& e);

struct Function1 {
    void* manager;
    void* functor;
    void (*invoker)(void*, CoordinateFrame);
    void operator()(CoordinateFrame a0) const;
};

void Function1::operator()(CoordinateFrame a0) const
{
    if (manager == 0)
        throw_exception(bad_function_call());
    invoker(functor, a0);
}
