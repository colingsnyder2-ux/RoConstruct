// from server: 100% by king_originala
struct Matrix
{
    float data[9];
    Matrix(const Matrix&);
};

struct Frame
{
    Matrix rotation;
    float x, y, z;
    Frame(const Frame&);
    ~Frame();
};

inline Frame::Frame(const Frame& other)
    : rotation(other.rotation), x(other.x), y(other.y), z(other.z)
{
}

inline Frame::~Frame()
{
}

struct Setter
{
    void set(Frame value);
};

struct Object
{
    char padding[8];
    Setter target;
};

struct Argument
{
    char padding[16];
    Object* object;
};

struct S
{
    Frame* value;
    void* f(void* result, Argument* argument);
};

void* S::f(void* result, Argument* argument)
{
    Setter* target = &argument->object->target;
    target->set(*value);
    return result;
}
