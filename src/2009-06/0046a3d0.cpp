// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CRITICAL_SECTION { void* d; long a; long b; void* c; void* e; unsigned long f; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
struct Vector2 {
    float x, y;
    Vector2() {}
    Vector2(const Vector2& o) : x(o.x), y(o.y) {}
};
class DxUserInput {
public:
    Vector2 getCursorPosition();
    Vector2 getCursorPositionWindowed();
    Vector2 getCursorPositionFullscreen();
private:
    char pad[0x2c];
    CRITICAL_SECTION cs;
    char pad2[0x18a - 0x2c - sizeof(CRITICAL_SECTION)];
    bool fullscreen;
};
Vector2 DxUserInput::getCursorPosition()
{
    EnterCriticalSection(&cs);
    Vector2 result = fullscreen ? getCursorPositionFullscreen() : getCursorPositionWindowed();
    LeaveCriticalSection(&cs);
    return result;
}
