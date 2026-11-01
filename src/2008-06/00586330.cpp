// from server: 100% by atomic.potato
struct Value;
extern void (__thiscall *destroyValue)(Value*);
extern void* __cdecl valueType();

struct Value
{
    char data[32];
    ~Value();
};

inline Value::~Value()
{
    destroyValue(this);
}

struct Object
{
    virtual ~Object();
};

struct Holder
{
    Object* value;
    Holder(const Value&);
    ~Holder();
    void swap(Holder&);
    void assign(const Value&);
};

inline Holder::~Holder()
{
    if (value)
        delete value;
}

inline void Holder::swap(Holder& other)
{
    if (this != &other)
    {
        Object* old = value;
        value = other.value;
        other.value = old;
    }
}

inline void Holder::assign(const Value& source)
{
    Holder(source).swap(*this);
}

struct Accessor
{
    virtual void slot0();
    virtual void slot1();
    virtual Value get(void*);
};

struct Result
{
    void* type;
    Holder value;
    void assign(const Value&);
};

inline void Result::assign(const Value& source)
{
    type = valueType();
    value.assign(source);
}

struct Descriptor
{
    char unused[24];
    Accessor* accessor;
    void getValue(void*, Result*) const;
};

void Descriptor::getValue(void* instance, Result* result) const
{
    result->assign(accessor->get(instance));
}
