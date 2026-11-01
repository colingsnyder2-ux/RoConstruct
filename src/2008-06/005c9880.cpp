// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);

struct Type {
    unsigned char data[16];
    Type(const char*, const void*);
    ~Type();
};

const Type& __cdecl singleton();
const Type& __cdecl valueType();
void* __stdcall makeDescriptor(void*, void*);
void* __cdecl lookup(void*, int);

struct Value {
    virtual ~Value();
    double number;
    Value(double);
};

struct Variant {
    const Type* type;
    Value* value;
    Variant(double);
    ~Variant();
};

struct Member {
    const Type* type;
    unsigned char data[32];
    void bind(void*, const Type&, Variant*);
};

struct Base {
    virtual ~Base();
    unsigned char data[16];
    Member member;
    Base(void*);
};

struct S : Base {
    unsigned int first;
    unsigned int second;
    Variant value;
    S(unsigned int, unsigned int, void*, void*, double, void*);
};

inline Value::Value(double n) : number(n)
{
}

inline Variant::Variant(double n)
    : type(&valueType()), value(new Value(n))
{
}

S::S(unsigned int a, unsigned int b, void* c, void* d,
     double n, void* e)
    : Base(makeDescriptor(c, e)), first(a), second(b), value(n)
{
    member.type = &singleton();
    member.bind(lookup(d, -1), valueType(), &value);
}
