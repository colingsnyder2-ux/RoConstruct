// from server: 100% by tajop
struct PropertyDescriptor;
extern const PropertyDescriptor prop_value;

struct MotorFeature {
    char pad[0xa4];
    int value;
    void raisePropertyChanged(const PropertyDescriptor& descriptor);
    void setValue(int newValue);
};

void MotorFeature::setValue(int newValue) {
    if (value != newValue) {
        value = newValue;
        raisePropertyChanged(prop_value);
    }
}
