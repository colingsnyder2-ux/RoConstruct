// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#pragma float_control(precise, off)
struct Vector3 { float x, y, z; };
extern char property;
struct S
{
    unsigned char padding[0x1b0];
    float x, y, z;
    unsigned char gap[0x1e8 - 0x1bc];
    int state;
    int mask;
    void notify(const void*);
    void f(const Vector3&);
};
void S::f(const Vector3& value)
{
    if (x != value.x || y != value.y || z != value.z)
    {
        x = value.x;
        y = value.y;
        z = value.z;
        notify(&property);
    }
    switch (state)
    {
    case 1:
    case 3:
        mask = 0xf0;
        state = 3;
        break;
    case 0:
    case 2:
        mask = 0;
        state = 1;
        break;
    }
}
