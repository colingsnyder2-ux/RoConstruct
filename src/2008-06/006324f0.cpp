// from server: 100% by king_originala
extern unsigned char name[];
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

struct Base {
    unsigned int data[82];
    Base(void*);
};

struct Vector {
    float x, y, z;
    __forceinline Vector(float, float, float);
};

__forceinline Vector::Vector(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

struct S : Base {
    float x, y, z;
    S();
};

S::S() : Base(name)
{
    data[0] = reinterpret_cast<unsigned int>(table0);
    data[4] = reinterpret_cast<unsigned int>(table10);
    data[5] = reinterpret_cast<unsigned int>(table14);
    data[8] = reinterpret_cast<unsigned int>(table20);
    data[9] = reinterpret_cast<unsigned int>(table24);
    data[17] = reinterpret_cast<unsigned int>(table44);
    data[25] = reinterpret_cast<unsigned int>(table64);
    data[33] = reinterpret_cast<unsigned int>(table84);
    data[41] = reinterpret_cast<unsigned int>(tableA4);
    data[49] = reinterpret_cast<unsigned int>(tableC4);
    data[76] = reinterpret_cast<unsigned int>(table130);
    data[78] = reinterpret_cast<unsigned int>(table138);

    static Vector axis(0.0f, 1.0f, 0.0f);
    x = axis.x;
    y = axis.y;
    z = axis.z;
}
