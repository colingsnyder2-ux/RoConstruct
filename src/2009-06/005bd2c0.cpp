// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /EHsc /MD
class X {
public:
    char pad[0xc];
    bool enabled;
    char pad2[0x37];
    int state;
    void setEnabled(bool value);
    void update();
};
void X::setEnabled(bool value)
{
    enabled = value;
    if (enabled && state == 3)
        state = 2;
    update();
}
