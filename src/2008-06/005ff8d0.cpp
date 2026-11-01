// from server: 100% by king_originala
extern char propertyDescriptor;

struct S
{
    char storage[0x1c4];
    int value;

    void applyValue(int newValue);
    void notify(const void *descriptor);
    void setValue(int newValue);
};

void S::setValue(int newValue)
{
    if (newValue != value)
    {
        applyValue(newValue);
        notify(&propertyDescriptor);
    }
}
