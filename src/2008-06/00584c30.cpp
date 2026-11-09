// from server: 100% by king_originala
struct Value
{
    char storage[0x34];
    virtual ~Value();
    Value(const Value&);
};

struct Holder
{
    Value* value;
    Holder(const Value&);
    ~Holder();
    void assign(const Value&);
    void swap(Holder& other);
};

__forceinline Holder::~Holder()
{
    if (value)
        delete value;
}

__forceinline void Holder::swap(Holder& other)
{
    if (this != &other)
    {
        Value* oldValue = other.value;
        Value* newValue = value;
        value = oldValue;
        other.value = newValue;
    }
}

__forceinline void Holder::assign(const Value& source)
{
    Holder(source).swap(*this);
}

struct Frame
{
    char storage[0x30];
};

struct Getter
{
    virtual void slot0();
    virtual void slot1();
    virtual const Value* get(Frame*, void*);
};

void* __cdecl getType();

struct Result
{
    void* type;
    Holder holder;
};

struct S
{
    char padding[0x18];
    Getter* getter;
    void f(void* object, Result* result);
};

void S::f(void* object, Result* result)
{
    Frame storage;
    const Value* value = getter->get(&storage, object);
    result->type = getType();
    result->holder.assign(*value);
}
