// from server: 100% by colin
extern float valueY;
extern float valueZ;

extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct Vector
{
    union
    {
        float x;
        unsigned int xBits;
    };
    float y, z;
    Vector();
};

inline Vector::Vector()
{
    y = valueY;
    xBits = 0;
    z = valueZ;
}

struct Table
{
    char padding[0xD0];
    Vector* entries[1];
};

struct Owner
{
    char padding[0x228];
};

struct S
{
    Owner* owner;
    int index;
    float f();
};

float S::f()
{
    Table* table = reinterpret_cast<Table*>(owner + 1);
    int idx = index;
    _ReadWriteBarrier();
    Vector* value = table->entries[idx];
    if (!value)
    {
        static Vector fallback;
        value = &fallback;
    }
    return value->y;
}
