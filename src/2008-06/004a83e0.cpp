// from server: 100% by king_originala
extern "C" void (__thiscall *destroy_string)(void*);

namespace std {
    template<class T> struct char_traits;
    template<class T> struct allocator;

    template<class C, class Traits, class Alloc>
    class basic_string {
        char storage[28];
    public:
        ~basic_string();
    };

    template<class C, class Traits, class Alloc>
    inline basic_string<C, Traits, Alloc>::~basic_string()
    {
        destroy_string(this);
    }
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

struct Prefix {
    char storage[20];
};

struct Base {
    int storage;
};

struct Derived : Prefix, Base {
};

struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual String get(Base*);
};

struct Argument {
    Object* object;
    Base* value;
};

struct S {
    void apply(int, const String&);
    void f(const Argument*, int);
};

void S::f(const Argument* argument, int value)
{
    Derived* derived = static_cast<Derived*>(argument->value);
    Object* object = reinterpret_cast<const volatile Argument*>(argument)->object;
    String text = object->get(static_cast<Base*>(derived));
    apply(value, text);
}
