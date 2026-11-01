// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;

    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Matrix3 {
    float elements[9];
    Matrix3(const Matrix3&);
};

struct Frame {
    Matrix3 rotation;
    Vector3 translation;

    Frame(const Frame& f)
        : rotation(f.rotation), translation(f.translation) {}
};

struct State {
    bool enabled();
};

struct Object {
    int* state();
    const Frame* frame();
    void setFrame(const Frame&);
};

extern int __cdecl classify(const Vector3&, const Frame&);
extern const Matrix3& __cdecl identity();

void __cdecl update(Object* object)
{
    if (reinterpret_cast<State*>(object->state())->enabled()) {
        const Frame* source = object->frame();
        Frame value(*source);
        static Vector3 up(0.0f, 1.0f, 0.0f);

        if (classify(up, value) != 1) {
            value.rotation = identity();
            object->setFrame(value);
        }
    }
}
