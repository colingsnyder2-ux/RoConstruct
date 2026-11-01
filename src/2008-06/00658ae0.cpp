// from server: 100% by king_originala
struct Vec3 {
    float x, y, z;
    Vec3(float a, float b, float c);
    Vec3(const Vec3& other);
    static const Vec3& zero();
};

inline Vec3::Vec3(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

inline Vec3::Vec3(const Vec3& other)
    : x(other.x), y(other.y), z(other.z)
{
}

inline const Vec3& Vec3::zero()
{
    static Vec3 value(0.0f, 0.0f, 0.0f);
    return value;
}

struct __declspec(align(4)) A {
    unsigned char data[48];
    A();
};

struct B {
    unsigned char data[24];
    B();
};

struct C {
    A a;
    B b;
};

struct S {
    int value;
    float elapsed;
    bool enabled;
    C state;
    float f54, f58, f5c, f60;
    float f64, f68, f6c, f70, f74, f78;
    int unused;
    float f80;
    Vec3 v84, v90, v9c, va8;

    S(int);
};

S::S(int argument)
    : value(argument),
      elapsed(0.0f),
      enabled(true),
      f54(0.0f),
      f58(0.0f),
      f5c(0.0f),
      f60(1.0f),
      f64(0.0f),
      f68(0.0f),
      f6c(0.0f),
      f70(0.0f),
      f74(0.0f),
      f78(0.0f),
      f80(0.0f),
      v84(Vec3::zero()),
      v90(Vec3::zero()),
      v9c(Vec3::zero()),
      va8(Vec3::zero())
{
}
