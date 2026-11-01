// from server: 100% by king_originala
struct Getter {
    virtual void slot0();
    virtual void slot1();
    virtual int get(int value);
};

struct EnumDescriptor {
    void convert(void* result, const int* value);
};

extern void __cdecl registerEnum(void (__cdecl* initializer)(), int* flag);
extern EnumDescriptor* __cdecl getEnumDescriptor();

struct S {
    char padding[28];
    Getter* getter;

    void* convert(void* result, int value);
};

void* S::convert(void* result, int value)
{
    volatile int state = 0;
    value = getter->get(value);
    registerEnum(
        reinterpret_cast<void (__cdecl*)()>(0x5ed620),
        reinterpret_cast<int*>(0x97b11c));
    EnumDescriptor* descriptor = getEnumDescriptor();
    descriptor->convert(result, &value);
    return result;
}
