// from server: 100% by king_originala
extern unsigned char propertyA;
extern unsigned char propertyB;

struct Settings {
    unsigned char padding[0x1e4];
    int value;

    void notify(void*);
    void setValue(int);
};

void Settings::setValue(int v)
{
    if (v != value) {
        value = v;
        notify(&propertyA);
        notify(&propertyB);
    }
}
