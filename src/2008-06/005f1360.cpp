// from server: 100% by colin
extern const float initialFirst;
extern const float initialSecond;

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

struct Value {
    int type;
    float first;
    float second;
    Value(float a, float b);
};

inline Value::Value(float a, float b)
    : type(0), first(a), second(b)
{
}

struct Properties {
    char padding[0xd0];
    Value* values[6];
};

struct Part {
    char padding[0x228];
    Properties properties;
};

struct FaceInstance {
    Part* part;
    int face;
    float getValue() const;
};

float FaceInstance::getValue() const
{
    Properties* properties = &part->properties;
    int index = face;
    _ReadWriteBarrier();
    Value* value = properties->values[index];
    if (!value) {
        static Value fallback(initialFirst, initialSecond);
        value = &fallback;
    }
    return value->second;
}
