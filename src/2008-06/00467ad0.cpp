// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern "C" {
    __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
    __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
}
struct Rect { long left, top, right, bottom; };
extern "C" { __declspec(dllimport) int __stdcall GetClientRect(void*, Rect*); }
struct WindowOwner { char reserved[0x20]; void* window; };
namespace G3D {
class Vector2 {
public:
    float x, y;
    inline Vector2() : x(0.0f), y(0.0f) {}
    inline Vector2(float _x, float _y) : x(_x), y(_y) {}
    inline Vector2(const Vector2& v) { x = v.x; y = v.y; }
    inline Vector2& operator=(const Vector2& v) { x = v.x; y = v.y; return *this; }
    inline Vector2 operator+(const Vector2& v) const { return Vector2(x + v.x, y + v.y); }
    inline Vector2 operator*(float s) const { return Vector2(s*x, s*y); }
    inline Vector2& operator+=(const Vector2& v) { x += v.x; y += v.y; return *this; }
    inline Vector2& operator*=(float s) { x *= s; y *= s; return *this; }
};
inline Vector2 operator*(float s, const Vector2& v) { return v * s; }
}
using G3D::Vector2;
struct DxUserInput {
    char reserved0[0x34];
    char criticalSection[0x2c];
    Vector2 offset;
    char reserved1[0x104];
    WindowOwner* owner;
    Vector2 getPosition();
    Vector2 getWindowSize() { Rect r; GetClientRect(owner->window, &r); return Vector2((float)(r.right - r.left), (float)(r.bottom - r.top)); }
    Vector2 getWindowCenter() { return getWindowSize() * 0.5f; }
};
Vector2 DxUserInput::getPosition()
{
    EnterCriticalSection(criticalSection);
    Vector2 result = getWindowSize() * 0.5f + offset;
    LeaveCriticalSection(criticalSection);
    return result;
}
