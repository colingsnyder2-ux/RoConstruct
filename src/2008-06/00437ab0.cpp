// from server: 100% by king_originala
struct Value {
    void* data;
    Value(const Value&);
    ~Value();
};

Value __cdecl convert(int);

struct S {
    char padding[0x10c];
    int color;

    void set(Value);
    void f(int);
};

void S::f(int value)
{
    color = value;
    set(convert(value));
}
