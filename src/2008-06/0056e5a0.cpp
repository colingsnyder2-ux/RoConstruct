// from server: 100% by king_originala
struct String;
extern void (__thiscall *string_construct)(String*);
extern void (__thiscall *string_destroy)(String*);

struct String {
    char storage[28];
    String();
    ~String();
};

inline String::String() { string_construct(this); }
inline String::~String() { string_destroy(this); }

struct Value {
    bool getString(String*);
};

struct Argument {
    char padding[16];
    Value value;
    bool isEmpty();
};

struct Setter {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void set(void*, String*);
};

struct S {
    char padding[24];
    Setter* setter;
    void f(void*, Argument*, void*);
};

void S::f(void* object, Argument* argument, void*)
{
    if (!argument->isEmpty()) {
        String value;
        if (argument->value.getString(&value))
            setter->set(object, &value);
    }
}
