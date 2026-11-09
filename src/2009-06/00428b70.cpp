// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Color3uint8 {
    unsigned char r, g, b;
};

struct BrickColor {
    int value;
    Color3uint8 color8() const;
    static BrickColor current;
};

struct ColorPopup {
    void SetColor(unsigned long);
};

struct CommandBars {
    ColorPopup* FindControl(int, int, int, int);
};

struct CMainFrame {
    char pad[0xec];
    CommandBars* bars;
    long OnUpdateColor(unsigned int, long);
};

long CMainFrame::OnUpdateColor(unsigned int, long)
{
    BrickColor color = BrickColor::current;
    Color3uint8 rgb = color.color8();
    unsigned long value = (((unsigned long)rgb.b << 8) | rgb.g) << 8;
    value |= rgb.r;

    ColorPopup* popup = bars->FindControl(2, 0x8040, 1, 1);
    if (popup)
        popup->SetColor(value);
    return 0;
}
