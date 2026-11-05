// from server: 100% by king_originala
unsigned int __cdecl getName();

extern unsigned char bodyThrustName[];
extern unsigned char table0[];
extern unsigned char table10[];
extern unsigned char table14[];
extern unsigned char table20[];
extern unsigned char table24[];
extern unsigned char table44[];
extern unsigned char table64[];
extern unsigned char table84[];
extern unsigned char tableA4[];
extern unsigned char tableC4[];
extern unsigned char table130[];
extern unsigned char table138[];

struct Vector {
    float x, y, z;
    Vector(float a, float b, float c);
    static const Vector& direction();
    static const Vector& origin();
};

inline Vector::Vector(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

inline const Vector& Vector::direction()
{
    static Vector value(0.0f, 1.0f, 0.0f);
    return value;
}

inline const Vector& Vector::origin()
{
    static Vector value(0.0f, 0.0f, 0.0f);
    return value;
}

struct S {
    unsigned char storage[0x148];
    float forceX, forceY, forceZ;
    float positionX, positionY, positionZ;

    S* initialize();
};

S* S::initialize()
{
    typedef unsigned int (__thiscall *InitializeBase)(S*, const char*);
    reinterpret_cast<InitializeBase>(&getName)(
        this, reinterpret_cast<const char*>(bodyThrustName));

    *reinterpret_cast<unsigned char**>(storage + 0x00) = table0;
    *reinterpret_cast<unsigned char**>(storage + 0x10) = table10;
    *reinterpret_cast<unsigned char**>(storage + 0x14) = table14;
    *reinterpret_cast<unsigned char**>(storage + 0x20) = table20;
    *reinterpret_cast<unsigned char**>(storage + 0x24) = table24;
    *reinterpret_cast<unsigned char**>(storage + 0x44) = table44;
    *reinterpret_cast<unsigned char**>(storage + 0x64) = table64;
    *reinterpret_cast<unsigned char**>(storage + 0x84) = table84;
    *reinterpret_cast<unsigned char**>(storage + 0xA4) = tableA4;
    *reinterpret_cast<unsigned char**>(storage + 0xC4) = tableC4;
    *reinterpret_cast<unsigned char**>(storage + 0x130) = table130;
    *reinterpret_cast<unsigned char**>(storage + 0x138) = table138;

    const Vector& direction = Vector::direction();
    forceX = direction.x;
    forceY = direction.y;
    forceZ = direction.z;

    const Vector& origin = Vector::origin();
    positionX = origin.x;
    positionY = origin.y;
    positionZ = origin.z;

    return this;
}
