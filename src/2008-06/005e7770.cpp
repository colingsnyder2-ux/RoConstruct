// from server: 100% by king_originala
#pragma float_control(precise, off)

extern float defaultFirst;
extern float defaultSecond;

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Value {
    int kind;
    float first;
    float second;

    Value();
    bool isEmpty() const;
};

inline Value::Value()
{
    float initialFirst = defaultFirst;
    kind = 0;
    first = initialFirst;
    second = defaultSecond;
}

struct Ball {
    char padding[0xD0];
    Value* values[1];

    void setValue(int index, const Value& value);
};

void Ball::setValue(int index, const Value& value)
{
    if (!values[index] && value.isEmpty())
        return;

    if (values[index] &&
        values[index]->kind == value.kind &&
        values[index]->first == value.first &&
        values[index]->second == value.second)
        return;

    if (value.isEmpty()) {
        delete values[index];
        values[index] = 0;
        return;
    }

    if (!values[index])
        values[index] = new Value;

    *values[index] = value;
}
