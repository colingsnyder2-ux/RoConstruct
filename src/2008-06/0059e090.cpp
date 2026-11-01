// from server: 100% by colin
// from server: 92% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern const float upperLimit;
extern char propertyDescriptor;

struct Value {
    char storage[0xB0];
    void set(float);
};

struct Settings {
    char padding[0x228];
    Value value;
    float current;

    void notify(void*);
    void set(float);
};

void Settings::set(float amount)
{
    float clamped = amount <= 0.0f ? 0.0f :
                    upperLimit <= amount ? upperLimit : amount;

    if (clamped != current) {
        value.set(clamped);
        notify(&propertyDescriptor);
    }
}
