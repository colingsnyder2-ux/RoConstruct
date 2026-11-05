// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
struct Vector2int16 {
    short x, y;
    Vector2int16() {}
    Vector2int16(short x_, short y_) : x(x_), y(y_) {}
};
struct Vector2 {
    float x, y;
    Vector2() {}
    Vector2(float x_, float y_) : x(x_), y(y_) {}
};
class DxUserInput;
struct UIEvent {
    int type;
    DxUserInput* source;
    Vector2int16 position;
    Vector2int16 delta;
    Vector2int16 windowSize;
    UIEvent(DxUserInput* s, int t, Vector2int16 size);
};
int __cdecl getButton(int code);

class DxUserInput {
public:
    char pad0[0x58];
    bool ignoreClick;
    Vector2int16 getWindowSize();
    void fireEvent(const UIEvent& e);
    void setKeyboardDirty(bool value);
    void postMouseEvent(int type, const Vector2& pos);
    void setCursorPosition(const Vector2& pos);
    void processMessage(unsigned int msg, int wParam, long lParam);
};

void DxUserInput::processMessage(unsigned int msg, int wParam, long lParam)
{
    switch (msg) {
    case 0x0100: // WM_KEYDOWN
    case 0x0101: // WM_KEYUP
        setKeyboardDirty(true);
        break;
    case 0x0021: // WM_MOUSEACTIVATE
        ignoreClick = true;
        break;
    case 0x0007: // WM_SETFOCUS
        {
            UIEvent e(this, 0xd, getWindowSize());
            fireEvent(e);
        }
        break;
    case 0x0008: // WM_KILLFOCUS
        {
            UIEvent e(this, 0xc, getWindowSize());
            fireEvent(e);
        }
        break;
    case 0x0200:
    case 0x0201:
    case 0x0202:
    case 0x0204:
    case 0x0205:
        if (ignoreClick && msg == 0x0201) {
            ignoreClick = false;
            break;
        }
        {
            Vector2 pos((float)(short)(lParam & 0xffff), (float)(short)((unsigned long)lParam >> 16));
            postMouseEvent(getButton(msg), pos);
            setCursorPosition(pos);
        }
        break;
    case 0x020a: // WM_MOUSEWHEEL
        {
            Vector2 pos((float)(short)(lParam & 0xffff), (float)(short)((unsigned long)lParam >> 16));
            postMouseEvent(wParam > 0.0 ? 8 : 9, pos);
        }
        break;
    case 0x0211:
    case 0x0231:
        return;
    }
}
