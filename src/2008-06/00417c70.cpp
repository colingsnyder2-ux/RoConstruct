// from server: 100% by king_originala
struct String;

typedef const char* (__thiscall *StringCStr)(const String*);
typedef void (__thiscall *StringDestroy)(String*);

extern StringCStr string_c_str;
extern StringDestroy string_destroy;

struct String {
    unsigned char data[28];
    const char* c_str() const;
    ~String();
};

inline const char* String::c_str() const
{
    return string_c_str(this);
}

inline String::~String()
{
    string_destroy(this);
}

struct Lock {
    int value;
    unsigned char flag;
    int count;
    void enter();
    void leave();
};

struct Guard {
    Lock* lock;
    bool acquired;
    Guard(Lock& value);
    ~Guard();
};

inline Guard::Guard(Lock& value) : lock(&value), acquired(false)
{
    lock->enter();
    acquired = true;
}

inline Guard::~Guard()
{
    if (acquired)
        lock->leave();
}

struct Function {
    void invoke(const char*);
};

struct Object {
    unsigned char padding[0x130];
    Lock lock;
    Function* function;
    void f(String value);
};

void Object::f(String value)
{
    Guard guard(lock);
    if (function)
        function->invoke(value.c_str());
}
