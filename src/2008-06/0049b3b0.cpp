// from server: 100% by king_originala
extern "C" void* __stdcall resolve_type(void*, void*);

struct Value
{
    void* type;
    unsigned int data;

    Value();
    ~Value();
};

struct Base
{
    unsigned char storage[52];

    Base(void*);
    virtual ~Base();
};

struct S : Base
{
    unsigned int first;
    unsigned int second;
    Value value1;
    Value value2;

    S(unsigned int, unsigned int, void*, void*, void*, void*);
    virtual ~S();
    void initialize(void*, void*);
};

S::S(unsigned int a, unsigned int b, void* c, void* d, void* e, void* f)
    : Base(resolve_type(c, f)), first(a), second(b), value1(), value2()
{
    initialize(d, e);
}
