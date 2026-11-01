// from server: 100% by king_originala
struct String
{
    char data[28];
    String(const String&);
};

extern void (__thiscall *string_copy_ctor)(String*, const String*);

inline String::String(const String& other)
{
    string_copy_ctor(this, &other);
}

struct Value
{
    String text;
    int extra;
};

struct Base
{
    const Value& get();
};

struct Object
{
    char data[20];
};

#pragma pointers_to_members(full_generality, multiple_inheritance)

struct S
{
    char pad[8];
    const Value& (Base::*fn)();
    Value method(Object*);
};

Value S::method(Object* object)
{
    volatile int temporary = 0;
    Base* base = 0;
    if (object != 0)
        base = reinterpret_cast<Base*>(reinterpret_cast<char*>(object) - 20);
    return (base->*fn)();
}
