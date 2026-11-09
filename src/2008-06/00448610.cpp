// from server: 100% by king_originala
enum Value { ValueZero = 0 };

struct Converter {
    bool convert(int value, int& result);
};

struct Setter {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void set(void* object, const Value& value) = 0;
};

struct S {
    char padding[0x1c];
    Setter* setter;
    Converter* converter;

    bool f(void* object, int value);
};

bool S::f(void* object, int value)
{
    if (converter->convert(value, value)) {
        value = *reinterpret_cast<volatile int*>(&value);
        setter->set(object, reinterpret_cast<const Value&>(value));
        return true;
    }
    return false;
}
