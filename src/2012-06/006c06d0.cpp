// from server: 42% by atomic.potato
struct TypedPropertyDescriptor
{
    char pad0[0x24];
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    void copyFrom(const TypedPropertyDescriptor& other);
};

void TypedPropertyDescriptor::copyFrom(const TypedPropertyDescriptor& other)
{
    int i;
    for (i = 0; i < 9; ++i)
        ((int*)this)[i] = ((const int*)&other)[i];
    f24 = other.f24;
    f28 = other.f28;
    f2c = other.f2c;
    f30 = other.f30;
    f34 = other.f34;
    f38 = other.f38;
}
