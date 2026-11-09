// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Matrix {
    float elements[9];
    Matrix(const Matrix&);
};

struct Vector {
    float x, y, z;
    Vector(const Vector&);
    Vector& operator=(const Vector&);
};

inline Vector::Vector(const Vector& other)
    : x(other.x), y(other.y), z(other.z)
{
}

inline Vector& Vector::operator=(const Vector& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

struct Frame {
    Matrix rotation;
    Vector translation;
};

struct Object {
    const Frame* getFrame();
    bool needsAdjustment();
    void setFrame(const Frame&);
};

extern const float adjustment;
extern Frame __cdecl adjustFrame(const Frame&, float);

void __cdecl updateFrame(Object* object, const Vector& offset)
{
    const Frame* source = object->getFrame();
    Frame frame = { source->rotation, source->translation };

    frame.translation.x += offset.x;
    frame.translation.y += offset.y;
    frame.translation.z += offset.z;

    if (object->needsAdjustment())
        frame = adjustFrame(frame, adjustment);

    object->setFrame(frame);
}
