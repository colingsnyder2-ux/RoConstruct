// from server: 100% by king_originala
struct Value
{
    float get();
};

struct S
{
    char padding[0x158];
    Value value;

    void setValue(const float &value);
    void f();
};

void S::f()
{
    float result = value.get();
    setValue(result);
}
