// from server: 100% by EspClaude
// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Vector {
    float x, y, z;

    Vector() {}
    Vector(const Vector&);
    Vector& operator=(const Vector&);
    Vector clamp(const Vector&, const Vector&) const;
};

inline Vector::Vector(const Vector& v) : x(v.x), y(v.y), z(v.z) {}

inline Vector& Vector::operator=(const Vector& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

inline const float& maximum(const float& a, const float& b)
{
    return b > a ? b : a;
}

inline const float& maximum2(const float& a, const float& b) { return a < b ? b : a; }
struct Box {
    Vector low, high;
};

extern const Vector& __cdecl combine(const Vector&, const Vector&);

struct S {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual Box bounds();

    char padding[0x130];
    Vector value;

    Vector f();
};

Vector S::f()
{
    const float zero = 0.0f;
    value.y = maximum(zero, value.y);
    float savedY = value.y;

    Box box = bounds();
    Vector clipped = value.clamp(box.low, box.high);
    value = clipped;
    value.y = maximum2(savedY, box.low.y);
    value = combine(clipped, value);
    return value;
}
