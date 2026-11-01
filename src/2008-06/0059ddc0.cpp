// from server: 100% by king_originala
extern char descriptor;

struct Property {
    char storage[0xA9];
    void set(bool value);
};

struct S {
    char padding[0x228];
    Property property;
    bool value;

    void notify(const void* descriptor);
    void setValue(bool newValue);
};

void S::setValue(bool newValue)
{
    if (newValue != value) {
        property.set(newValue);
        notify(&descriptor);
    }
}
