// from server: 33% by colin
struct Vector3 {
    float x, y, z;
};

struct CoordinateFrame {
    float r0, r1, r2, r3;
    float r4, r5, r6, r7;
    float r8, r9, r10, r11;
};

struct Adorn {
    void drawLine(const Vector3& a, const Vector3& b, const Vector3& c, const Vector3& d, unsigned int color, float thickness);
};

struct Instance {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void getWorldPosition(Vector3* out);
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void getWorldTransform(CoordinateFrame* out);
};

struct Hint {
    char pad[0x10];
    void render2d(Adorn* adorn, int arg);
};

extern float g_float_797e9c;
extern float g_float_79b500;
extern double g_double_7bfe68;

Vector3* getCameraPos();
Vector3* getCameraLook();
unsigned int getColor();

void Hint::render2d(Adorn* adorn, int arg)
{
    Vector3 pos;
    ((Instance*)this)->getWorldPosition(&pos);

    float a = pos.x;
    float b = g_float_79b500 - pos.y;
    float c = pos.z;
    float d = pos.y + g_float_79b500;

    float e = a * g_float_797e9c;
    float f = c * g_float_797e9c;

    Vector3 camPos = *getCameraPos();
    Vector3 camLook = *getCameraLook();

    Vector3 v1;
    v1.x = camPos.x;
    v1.y = camPos.y;
    v1.z = camPos.z;

    Vector3 v2;
    v2.x = camLook.x;
    v2.y = camLook.y;
    v2.z = camLook.z;

    Vector3 v3;
    v3.x = e;
    v3.y = b;
    v3.z = f;

    Vector3 v4;
    v4.x = a;
    v4.y = d;
    v4.z = c;

    CoordinateFrame cf;
    ((Instance*)this)->getWorldTransform(&cf);

    Vector3 v5;
    v5.x = camPos.x;
    v5.y = camPos.y;
    v5.z = camPos.z;

    Vector3 v6;
    v6.x = camLook.x;
    v6.y = camLook.y;
    v6.z = camLook.z;

    unsigned int color = getColor();

    adorn->drawLine(v3, v4, v5, v6, color, (float)g_double_7bfe68);
}
