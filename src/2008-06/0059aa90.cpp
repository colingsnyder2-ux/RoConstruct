// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

struct Body {
    char pad[0x94];
    Vector3 value;
    void updatePV();
};

struct Primitive {
    char pad[0xa0];
    Body* body;
    const Vector3& getValue();
};

struct Matrix3 {
    float elements[9];
};

struct Frame {
    Matrix3 rotation;
    Vector3 position;

    Frame& operator=(const Frame& value);
};

__forceinline Frame& Frame::operator=(const Frame& value)
{
    rotation = value.rotation;
    position.x = value.position.x;
    position.y = value.position.y;
    position.z = value.position.z;
    return *this;
}

struct Temporary {
    char data[0x68];
};

struct Cache {
    char pad[0x38];
    Frame frame;
    void prepare(Temporary* value);
};

struct Part {
    char pad[0x228];
    Primitive primitive;
    char gap[0x64];
    Cache cache;

    Cache& getCache();
};

Cache& Part::getCache()
{
    Temporary temporary;
    Cache& result = cache;
    result.prepare(&temporary);
    result.frame =
        *reinterpret_cast<const Frame*>(&primitive.getValue());
    return result;
}
