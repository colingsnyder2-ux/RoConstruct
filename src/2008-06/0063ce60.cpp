// from server: 100% by colin
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Value {
    unsigned int data[6];

    Value();
    Value(const Value&);
};

inline Value::Value()
{
}

inline Value::Value(const Value& source)
{
    data[0] = source.data[0];
    data[1] = source.data[1];
    data[2] = source.data[2];
    data[3] = source.data[3];
    data[4] = source.data[4];
    data[5] = source.data[5];
}

struct Object {
    unsigned char data[40];
    Object();
};

struct Count {
    void* pointer;

    Count();
    ~Count();
};

inline Count::Count() : pointer(0)
{
}

struct Owner {
    void* first;
    Count second;

    Owner();
    void assign(Object*);
};

inline Owner::Owner() : first(0)
{
}

struct Holder {
    void* table;
    unsigned int reserved;
    Value value;

    Holder(const Value&);
    ~Holder();
    void set(const Value&);
};

inline Holder::Holder(const Value& source)
{
    Value copy = source;
    table = 0;
    set(copy);
}

struct S : Owner {
    Holder holder;

    S(const Value&);
    void finish();
};

S::S(const Value& source) : holder(source)
{
    assign(new Object);
    finish();
}
