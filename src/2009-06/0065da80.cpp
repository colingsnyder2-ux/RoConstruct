// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Vector3 { float x, y, z; };
struct Matrix3 { float elements[9]; };
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
struct Temporary { char data[0x68]; };
struct Cache {
    char pad[0x38];
    Frame frame;
    void prepare(Temporary* value);
};
struct Part {
    char pad[0x170];
    Cache cache;
    Frame getCoordinateFrame() const;
    Cache& getCache();
};
Cache& Part::getCache()
{
    Temporary temporary;
    Cache& result = cache;
    result.prepare(&temporary);
    result.frame = getCoordinateFrame();
    return result;
}
