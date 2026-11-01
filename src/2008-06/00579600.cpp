// from server: 100% by king_originala
extern "C" void* __cdecl getDescriptor();
extern "C" void* __cdecl getValueType();

void* __cdecl operator new(unsigned int);

struct Base {
    char storage[52];
    Base(void*, const char*, int);
    virtual ~Base();
};

struct Value {
    void* type;
    void* data;
    Value();
    ~Value();
};

struct Flag {
    bool value;
    Flag(bool);
    virtual ~Flag();
};

inline Flag::Flag(bool enabled) : value(enabled) {}

struct FlagOwner {
    Flag* pointer;
    FlagOwner(Flag*);
    ~FlagOwner();
};

inline FlagOwner::FlagOwner(Flag* p) : pointer(p) {}

struct S : Base {
    void* first;
    void* second;
    Value value1;
    Value value2;
    void* type;
    FlagOwner flag;

    S(void*, void*, const char*, const char*, void*, void*, bool, int);
    virtual ~S();
    void set(const char*, void*, void*);
};

S::S(void* a, void* b, const char* name, const char* text,
     void* c, void* d, bool enabled, int options)
    : Base(getDescriptor(), name, options),
      first(a),
      second(b),
      value1(),
      value2(),
      type(getValueType()),
      flag(new Flag(enabled))
{
    set(text, c, d);
}
