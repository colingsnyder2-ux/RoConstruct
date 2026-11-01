// from server: 100% by king_originala
#pragma float_control(precise, off)

extern const float scaleX;
extern const float scaleY;

struct Pair {
    float x;
    float y;
};

struct S {
    void setY(float);
    void setX(float);
    void f(const Pair&);
};

void S::f(const Pair& value)
{
    setY(value.y * scaleY);
    setX(value.x * scaleX);
}
