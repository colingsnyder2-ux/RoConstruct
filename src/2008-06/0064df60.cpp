// from server: 100% by king_originala
struct Value {
    int fields[5];
};

struct S {
    char pad[0x130];
    Value value;
    void set(const Value& source);
};

void S::set(const Value& source)
{
    value = source;
    value.fields[0] = 0;
}
