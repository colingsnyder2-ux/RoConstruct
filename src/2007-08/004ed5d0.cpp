// from server: 88% by EspClaude
// from server: 42% by colin
// roc 2007-08 004ed5d0  unit: CylinderBuilder  size: 799 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ed5d0

// roc-flags: /O2 /GS /EHsc /MD /QIfist
// Target bytes: disassemble clients/2007-08/Roblox.exe at 0x4ed5d0 (799 bytes).
// Shape follows the 2008-06 sibling (rbxgs Builder::build, 2008 0x4ff790) adapted to the
// 2007-08 bytes: double constants 0.5 (0x795b48), 0.25 (0x79f348), 4.0 (0x79f340);
// float constants 0.25 (0x787050), 0.5 (0x797e9c); ceil via MSVCR80 IAT (0x77e930);
// surfaceTypes at this+0x10, halfSize at this+4, textureScale at this+0x18.
// The target rounds with fld/fistp (G3D lrintf); /QIfist reproduces that conversion.

#include <math.h>

namespace G3D {
inline int iRound(float f) { return (int)f; }
struct Vector2 {
    float x, y;
    Vector2() : x(0), y(0) {}
    Vector2(float x_, float y_) : x(x_), y(y_) {}
    Vector2(const Vector2& v) : x(v.x), y(v.y) {}
    Vector2& operator=(const Vector2& v) { x = v.x; y = v.y; return *this; }
    float& operator[](int i) { return (&x)[i]; }
    const float& operator[](int i) const { return (&x)[i]; }
    Vector2 operator-() const { return Vector2(-x, -y); }
};
struct Vector3 {
    float x, y, z;
    Vector3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
    float& operator[](int i) { return (&x)[i]; }
    const float& operator[](int i) const { return (&x)[i]; }
    Vector2 xy() const;                       // call 0x50b010
};
struct Rect2D {
    Vector2 min, max;
    static Rect2D xyxy(const Vector2& v0, const Vector2& v1);   // call 0x4e0180
};
}

namespace MeshTypes {
struct Vector2int16 {
    short x, y;
    Vector2int16() : x(0), y(0) {}
    short& operator[](int i) { return (&x)[i]; }
    const short& operator[](int i) const { return (&x)[i]; }
};
template<class T> const T& maximum(const T& a, const T& b) { return a < b ? b : a; }
}

namespace RBX { namespace View {
using G3D::Vector2; using G3D::Vector3; using G3D::Rect2D; using MeshTypes::Vector2int16;
struct Function { int opaque[2]; };   // no /GS cookie in target: no char arrays
Vector3 __cdecl mapFace(const Vector3&);      // call 0x5b9970
float __cdecl surfaceOffset(int);             // call 0x4de980
static __forceinline bool useFirstAxis(int purpose, const Vector3& size) { if (purpose == 0 && size.x < size.y) return true; return false; }
static __forceinline Vector3 absoluteSize(const Vector3& v) { Vector3 mapped = mapFace(v); return Vector3(fabs(mapped.x), fabs(mapped.y), fabs(mapped.z)); }
struct Builder {
    virtual void build(int);
    const Vector3 halfSize;    // +4
    unsigned surfaceTypes;     // +0x10
    void* level;               // +0x14
    Vector2 textureScale;      // +0x18
    void build(Function, Vector2int16, int);
    void emit(Function, Rect2D, float, Vector2, Vector2, int, Vector2int16);   // call 0x4ec270
};

void Builder::build(Function function, Vector2int16 grid, int purpose)
{
    int surface = (surfaceTypes >> 0) & 7;
    Vector3 size = absoluteSize(halfSize);
    int axis = !useFirstAxis(purpose, size);
    int steps = (purpose == 0 && surface) ? G3D::iRound((float)ceil((double)(float)(size[axis] * 0.5))) : 1;
    Vector2int16 divisions;
    short n = grid[1 - axis];
    divisions[axis] = MeshTypes::maximum<short>(1, (short)(n / steps));
    divisions[1 - axis] = n;
    float depth = size.z;
    Vector2 begin = -size.xy();
    Vector2 end = size.xy();
    Vector2 origin, extent;
    switch (purpose) {
    case 0:
        if (!surface) { origin.x = 0.25f; origin.y = 0.5f; extent[1 - axis] = 0; extent[axis] = 0; }
        else { origin[1 - axis] = 0; origin[axis] = surfaceOffset(surface); extent[1 - axis] = size[1 - axis] * 2.0f; extent[axis] = 0.5f; if (axis == 1) extent.x = -extent.x; }
        break;
    case 1: origin.x = 0; origin.y = textureScale.y; extent.x = textureScale.x; extent.y = -textureScale.y; break;
    case 2: origin.x = 0; origin.y = 0; extent.x = 0; extent.y = 0; break;
    }
    for (int i = 0; i < steps; ++i) {
        if (i == steps - 1) { end[axis] = size[axis]; if (purpose == 0 && surface) extent[axis] = (end[axis] - begin[axis]) * 0.25 * extent[axis]; }
        else end[axis] = begin[axis] + 4.0;
        emit(function, Rect2D::xyxy(begin, end), depth, origin, extent, axis, divisions);
        begin[axis] = end[axis];
    }
}
}}
