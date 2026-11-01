// from server: 100% by king_originala
struct Matrix
{
    float data[9];
    Matrix(const Matrix&);
};

struct Vector
{
    float x, y, z;
    Vector(const Vector&);
};

__forceinline Vector::Vector(const Vector& other)
    : x(other.x), y(other.y), z(other.z)
{
}

struct Frame
{
    Matrix rotation;
    Vector position;
    Frame(const Frame&);
    ~Frame();
};

__forceinline Frame::Frame(const Frame& other)
    : rotation(other.rotation), position(other.position)
{
}

__forceinline Frame::~Frame()
{
}

struct Tag
{
};

struct Signal
{
    void fire(const Tag&, Frame);
};

struct Slot
{
    char padding[16];
    Signal signal;
};

struct Registry
{
    Slot* find(void*);
};

extern Registry registry;

struct S
{
    char padding[0x130];
    Frame frame;

    void f(void*);
};

void S::f(void*)
{
    void* owner = this ? reinterpret_cast<char*>(this) + 0x14 : 0;
    Frame value(frame);
    Slot* slot = registry.find(owner);
    if (slot)
    {
        Tag tag;
        slot->signal.fire(tag, value);
    }
}
