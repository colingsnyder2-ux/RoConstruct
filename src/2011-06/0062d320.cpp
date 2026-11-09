// from server: 65% by atomic.potato
extern "C" void __stdcall G1_basic_string_copy(void *destination, void *source);

struct BackpackItem
{
    int f(void *value);
    char data[300];
};

int BackpackItem::f(void *value)
{
    void *string_object = data + 300;
    G1_basic_string_copy(value, string_object);
    *(long *)((char *)value + 0x1c) = *(long *)((char *)string_object + 0x1c);
    return (int)value;
}
