// from server: 76% by atomic.potato
struct MotorFeature {
    char padding[160];
    int value;
    void setValue(int);
};

extern "C" void __declspec(noreturn) __stdcall sub_414da0(int);

void MotorFeature::setValue(int value)
{
    if (this->value != value) {
        this->value = value;
        sub_414da0(0xE525A0);
    }
}
