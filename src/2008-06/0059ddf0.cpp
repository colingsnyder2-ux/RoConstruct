// from server: 100% by king_originala
struct PropertyDescriptor;
extern PropertyDescriptor property;

struct Settings {
    char padding[0x1f0];
    bool value;

    void raisePropertyChanged(const PropertyDescriptor&);
    void setValue(bool);
};

void Settings::setValue(bool newValue)
{
    if (newValue != value) {
        value = newValue;
        raisePropertyChanged(property);
    }
}
