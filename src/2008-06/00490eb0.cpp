// from server: 100% by king_originala
struct Value {
    unsigned char data[32];
    ~Value();
};

struct Base {
    unsigned char data[32];
    Base(const Value &value);
};

struct S : Base {
    int field;
    S(Value value, int n);
};

S::S(Value value, int n) : Base(value), field(n)
{
}
