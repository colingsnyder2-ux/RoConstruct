// from server: 100% by king_originala
extern "C" void* __stdcall getDescriptor(const char*, unsigned);

struct Base {
    virtual ~Base();
    char storage[52];

    Base(void*);
};

struct Value {
    void* type;
    void* data;

    Value();
    ~Value();
};

struct Callback {
    unsigned first;
    unsigned second;
};

struct S : Base {
    Callback callback;
    Value firstValue;
    Value secondValue;

    S(Callback, const char*, const char*, const char*, unsigned);
    virtual ~S();
    void initialize(const char*, const char*);
};

S::S(Callback function, const char* name, const char* first,
     const char* second, unsigned flags)
    : Base(getDescriptor(name, flags)),
      callback(function),
      firstValue(),
      secondValue()
{
    initialize(first, second);
}
