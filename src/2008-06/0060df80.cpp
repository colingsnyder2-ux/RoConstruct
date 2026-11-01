// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Matrix {
    float data[9];
    Matrix(const Matrix&);
};

struct Vector {
    float x, y, z;
    Vector(float, float, float);
};

inline Vector::Vector(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

struct Frame {
    Matrix rotation;
    float x, y, z;
    ~Frame();
};

inline Frame::~Frame()
{
}

struct Part {
    bool blocked();
    Frame frame();
};

struct Shared {
    Part* object;
    Control* control;
    Shared(const Shared&);
    ~Shared();
};

inline Shared::~Shared()
{
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

bool __cdecl enabled(Shared);
Frame __cdecl transform(const Frame&, const Vector&);
void __cdecl update(void*, Frame, Frame);
bool __cdecl finish(void*);

struct Contact {
    unsigned char prefix[8];
    unsigned char state[1];
    Shared part();
    bool run();
};

bool Contact::run()
{
    if (enabled(part())) {
        Part* p = part().object;
        if (!p->blocked()) {
            Frame original = p->frame();
            static Vector direction(1.0f, 0.1f, 1.0f);
            Frame modified = transform(original, direction);
            update(state, original, modified);
        }
    }
    return finish(state);
}
