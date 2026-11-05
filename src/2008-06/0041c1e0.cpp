// from server: 56% by king_originala
struct Value {
    virtual ~Value();
};

struct Argument {
    Value* value;
    Argument(const Argument&);
    ~Argument() { if (value) delete value; }
};

struct S {
    char reserved[0x38];
    void (__thiscall *callback)(void*, Argument);
    int adjustment;
    void f(void*, Argument);
};

void S::f(void* object, Argument argument)
{
    callback(static_cast<char*>(object) + adjustment, argument);
}
