// from server: 100% by king_originala
struct Matrix {
    float m[9];
};

struct Vector3 {
    float x, y, z;
};

struct Frame {
    Matrix rotation;
    Vector3 translation;
    Frame();
};

struct Owner {
    bool query(Frame& frame);
};

extern const Vector3& getVector();
extern float scale;
extern void draw(void* context, const Frame* frame, int mode,
                 float weight, float scaleValue, const Vector3& vector);

struct S {
    void f(void* context);
};

void S::f(void* context)
{
    Frame frame;
    if (reinterpret_cast<Owner*>(reinterpret_cast<char*>(this) - 0x130)->query(frame))
        draw(context, &frame, 2, 1.0f, scale, getVector());
}
