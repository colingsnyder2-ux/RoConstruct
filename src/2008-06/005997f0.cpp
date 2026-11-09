// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
    bool differs(const Vector3& other) const;
};

struct Body;

struct Primitive {
    char pad[0xa0];
    Body* body;

    const Vector3& getValue();
    void setValue(const Vector3& value);
};

struct S {
    typedef void (__thiscall *Callback)(S*);

    Callback* volatile vtable;
    char pad[0x224];
    Primitive primitive;
    char gap[0xcc];
    volatile unsigned char dirty;

    void f(const Vector3& value);
};

void S::f(const Vector3& value)
{
    if (value.differs(primitive.getValue())) {
        primitive.setValue(value);
        dirty = 1;
        vtable[20](this);
    }
}
