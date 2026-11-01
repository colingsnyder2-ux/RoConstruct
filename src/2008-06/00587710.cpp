// from server: 100% by king_originala
struct Holder {
    virtual ~Holder();
    virtual void unused();
    virtual Holder* clone() const;
};

inline Holder* copyHolder(Holder* holder)
{
    Holder* result;
    if (holder)
        result = holder->clone();
    else
        result = 0;
    return result;
}

struct Value {
    unsigned int first;
    unsigned int second;
    Holder* holder;

    Value(const Value&);
    ~Value();
};

inline Value::Value(const Value& other)
    : first(other.first),
      second(other.second),
      holder(copyHolder(other.holder))
{
}

inline Value::~Value()
{
    if (holder)
        delete holder;
}

typedef void (__thiscall *Callback)(void*, Value*);

struct S {
    void* context;
    void f(unsigned int, Callback*, const Value* const*, unsigned int);
};

void S::f(unsigned int, Callback* callback,
          const Value* const* source, unsigned int)
{
    Value value(**source);
    void* receiver = context;
    (*callback)(receiver, &value);
}
