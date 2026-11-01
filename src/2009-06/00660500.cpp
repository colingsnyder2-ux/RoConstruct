// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern unsigned char property;

struct Value {
    unsigned char padding[0xF2];
    unsigned char value;

    void setValue(unsigned char v);
};

struct Settings {
    unsigned char padding[0x118];
    Value* setting;

    void notify(void*);
    void setEnabled(unsigned char v);
};

void Settings::setEnabled(unsigned char v)
{
    v = !v;
    if (v != setting->value) {
        setting->setValue(v);
        notify(&property);
    }
}
