// from server: 100% by king_originala
extern unsigned char property;

struct Value {
    unsigned char padding[0xAB];
    unsigned char value;

    void setValue(unsigned char v);
};

struct Settings {
    unsigned char padding[0x228];
    Value setting;

    void notify(void*);
    void setEnabled(unsigned char v);
};

void Settings::setEnabled(unsigned char v)
{
    v = !v;
    if (v != setting.value) {
        setting.setValue(v);
        notify(&property);
    }
}
