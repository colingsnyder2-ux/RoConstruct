// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /arch:SSE2 /fp:fast
struct Descriptor { int x; };
extern Descriptor desc_size;
struct TextBox {
    char pad[0x84];
    float fontSize;
    void raiseChanged(const Descriptor& d);
    void setFontSize(float v);
};
void TextBox::setFontSize(float v)
{
    if (fontSize != v) {
        fontSize = v;
        raiseChanged(desc_size);
    }
}