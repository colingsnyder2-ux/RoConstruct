// from server: 100% by king_originala
struct Vec3 {
    float x, y, z;
};

struct Vec4 {
    float x, y, z, w;
};

struct Matrix {
    float data[12];
};

extern const Vec3& __cdecl axisZ();
extern const Vec3& __cdecl axisY();
extern const Vec3& __cdecl axisX();
extern const float scalar;

struct Base {
    virtual Matrix getMatrix();
};

struct Receiver {
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
    virtual void setMatrix(const Matrix&);
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void setVectors(const Vec4&, const Vec4&, const Vec4&, float);
};

struct S {
    char padding[0x134];
    int* vbtable;
    void apply(Receiver*);
};

void S::apply(Receiver* receiver)
{
    Base* base = reinterpret_cast<Base*>(
        reinterpret_cast<char*>(this) + 0x134 + vbtable[2]);

    receiver->setMatrix(base->getMatrix());

    const Vec3& z = axisZ();
    Vec4 a = { z.x, z.y, z.z, 1.0f };

    const Vec3& y = axisY();
    Vec4 b = { y.x, y.y, y.z, 1.0f };

    const Vec3& x = axisX();
    Vec4 c = { x.x, x.y, x.z, 1.0f };

    receiver->setVectors(c, b, a, scalar);
}
