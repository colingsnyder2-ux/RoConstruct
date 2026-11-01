// from server: 100% by king_originala
struct Color3 {
    float r, g, b;
};

struct BrickColor {
    int value;
    Color3 color() const;
};

struct Color3uint8 {
    unsigned char r, g, b;
    Color3uint8(const Color3&);
};

struct ColorPopup {
    void SetColor(unsigned long);
};

struct CommandBars {
    ColorPopup* FindControl(int, int, int, int);
};

struct CMainFrame {
    void UpdateColor(int, BrickColor);
};

void CMainFrame::UpdateColor(int, BrickColor color)
{
    Color3uint8 rgb(color.color());
    unsigned long value = (((unsigned long)rgb.b << 8) | rgb.g) << 8;
    value |= rgb.r;

    CommandBars* bars = reinterpret_cast<CommandBars**>(this)[-1];
    ColorPopup* popup = bars->FindControl(2, 0x8040, 1, 1);
    if (popup)
        popup->SetColor(value);
}
