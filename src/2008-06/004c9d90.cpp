// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

__forceinline void increment(volatile long* counter)
{
    _InterlockedExchangeAdd(counter, 1);
}

struct ControlBlock {
    long reserved;
    volatile long references;
};

struct SharedHandle {
    void* object;
    ControlBlock* control;

    SharedHandle(const SharedHandle&);
    ~SharedHandle();
};

__forceinline SharedHandle::SharedHandle(const SharedHandle& other)
    : object(other.object), control(other.control)
{
    if (control)
        increment(&control->references);
}

struct Matrix {
    float values[9];
    Matrix(const Matrix&);
};

struct Camera {
    Matrix rotation;
    float x;
    float y;
    float z;
};

struct S {
    SharedHandle handle;
    double time;
    Camera camera;
    float value;
    int flags;
    float weight;

    S(const S&);
};

S::S(const S& other)
    : handle(other.handle),
      time(other.time),
      camera(other.camera),
      value(other.value),
      flags(other.flags),
      weight(other.weight)
{
}
