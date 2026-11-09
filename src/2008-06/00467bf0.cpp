// from server: 100% by king_originala
struct Point {
    long x;
    long y;
};

struct Vector2 {
    float x;
    float y;
};

extern "C" {
    extern void (__stdcall *EnterCriticalSection)(void*);
    extern void (__stdcall *LeaveCriticalSection)(void*);
    extern int (__stdcall *GetCursorPos)(Point*);
    extern int (__stdcall *ScreenToClient)(void*, Point*);
}

struct Window {
    char padding[0x20];
    void* handle;
};

struct DxUserInput {
    char padding0[0x34];
    char criticalSection[0x18];
    char padding1[0x120];
    Window* window;

    Vector2 getCursorPosition();
};

Vector2 DxUserInput::getCursorPosition()
{
    EnterCriticalSection(criticalSection);

    Point point;
    GetCursorPos(&point);
    ScreenToClient(window->handle, &point);

    Vector2 result;
    result.x = (float)point.x;
    result.y = (float)point.y;

    LeaveCriticalSection(criticalSection);
    return result;
}
