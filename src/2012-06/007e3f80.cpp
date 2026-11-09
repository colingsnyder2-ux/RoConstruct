// from server: 100% by tajop
struct Vector2 {
    float x, y;
    Vector2() {}
};

struct Vector3 {
    float x, y, z;
    Vector2 xz() const;
};

struct CoordinateFrame {
    float rotation[9];
    Vector3 translation;
};

struct Primitive {
    const CoordinateFrame& getCoordinateFrame();
};

struct Assembly {
    Primitive* getAssemblyPrimitive();
    Vector2 getPositionXZ();
};

Vector2 Assembly::getPositionXZ()
{
    return getAssemblyPrimitive()->getCoordinateFrame().translation.xz();
}
