// from server: 100% by EspClaude
// roc 2007-08 00463770  view resize: viewport Rect2D = (0,0)-(client size) from GetClientRect(view->m_hWnd) (view @+0x180, rect @+0x58)
// roc-flags: /O2 /GS /EHsc /MD
struct Vector2 {
    float x, y;
    Vector2() {}
    Vector2(float x, float y) : x(x), y(y) {}
    Vector2(const Vector2& v) : x(v.x), y(v.y) {}
    Vector2& operator=(const Vector2& v) { x = v.x; y = v.y; return *this; }
};
struct Rect2D {
    Vector2 min, max;
    Rect2D() {}
    Rect2D(const Vector2& lo, const Vector2& hi) : min(lo), max(hi) {}
};
struct WinRect { int left, top, right, bottom; };
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hwnd, WinRect* rect);
struct Window { char pad[0x20]; void* m_hWnd; };
class ViewBase {
    char pad[0x58];
    Rect2D viewport;
    char pad2[0x180 - 0x68];
    Window* view;
public:
    void updateViewport();
};
void ViewBase::updateViewport()
{
    WinRect rect;
    GetClientRect(view->m_hWnd, &rect);
    Vector2 size((float)(rect.right - rect.left), (float)(rect.bottom - rect.top));
    viewport = Rect2D(Vector2(0, 0), size);
}
