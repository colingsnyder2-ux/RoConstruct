// from server: 100% by king_originala
struct String;
extern void (__thiscall *destroyString)(String*);

struct String {
    char storage[28];
    ~String();
};

__forceinline String::~String()
{
    destroyString(this);
}

struct Holder {
    void* value;
    Holder(const String&);
    ~Holder();
};

struct Entry {
    void* type;
    void set(void* name, void* valueType, void* storage);
};

struct Base {
    virtual ~Base();
    char padding[16];
    Entry entry;
    char remainder[32];

    Base(void* descriptor);
};

struct Callback {
    unsigned first;
    unsigned second;
};

extern "C" void* __stdcall getDescriptor(const char*, unsigned);
extern "C" void* __cdecl getValueType();
extern "C" void* __cdecl getEntryType();
extern "C" void* __cdecl getName(const char*, int);

struct Value {
    void* type;
    Holder holder;

    Value(const String&);
};

__forceinline Value::Value(const String& text)
    : type(getValueType()), holder(text)
{
}

struct S : Base {
    Callback callback;
    Value value;

    S(Callback, const char*, const char*, String, unsigned);
    virtual ~S();
};

S::S(Callback function, const char* name, const char* category,
     String text, unsigned flags)
    : Base(getDescriptor(name, flags)),
      callback(function),
      value(text)
{
    entry.type = getEntryType();
    entry.set(getName(category, -1), getValueType(), &value);
}
