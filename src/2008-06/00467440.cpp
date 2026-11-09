// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Vector2int16 {
    short x;
    short y;
    Vector2int16(short x, short y) : x(x), y(y) {}
};

struct Vector2 {
    float x, y;
    Vector2(float x, float y) : x(x), y(y) {}
};

struct WinRect { int left, top, right, bottom; };

extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hwnd, WinRect* rect);

struct Window { char pad[0x20]; void* m_hWnd; };

struct CSettingsDialog {
    char pad[0x16c];
    Window* view;
    Vector2int16 getSize();
};

Vector2int16 CSettingsDialog::getSize() {
    WinRect rect;
    GetClientRect(view->m_hWnd, &rect);
    Vector2 size((float)(rect.right - rect.left), (float)(rect.bottom - rect.top));
    return Vector2int16((short)size.x, (short)size.y);
}
