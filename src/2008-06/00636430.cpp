// from server: 100% by king_originala
extern "C" void (__cdecl* invalid_parameter_noinfo)();
void* __cdecl operator new(unsigned int);

struct Value {
    Value(double);
    virtual ~Value();
    double number;
};

inline Value::Value(double n) : number(n)
{
}

struct Buffer {
    unsigned int state[3];
    Value** first;
    Value** last;
    Value** limit;

    Buffer(unsigned int);
    ~Buffer();
};

struct Receiver {
    virtual ~Receiver();
    virtual void apply(Buffer&);
};

struct S {
    Receiver* receiver;
    void f(double);
};

void S::f(double number)
{
    Buffer values(1);

    if (static_cast<unsigned int>(values.last - values.first) <= 0U)
        invalid_parameter_noinfo();

    Value** slot = values.first;
    Value* replacement = new Value(number);

    Value* previous = replacement;
    if (static_cast<void*>(&number) != static_cast<void*>(slot)) {
        previous = *slot;
        *slot = replacement;
    }

    if (previous)
        delete previous;

    receiver->apply(values);
}
