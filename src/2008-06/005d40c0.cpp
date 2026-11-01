// from server: 100% by king_originala
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
        char storage[32];
    public:
        ~basic_string();
    };
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

extern void (__thiscall* string_destroy)(String*);

template<class T, class Traits, class Alloc>
__forceinline std::basic_string<T, Traits, Alloc>::~basic_string()
{
    string_destroy(this);
}

struct Service {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, const String&);
};

extern Service* service;

struct S {
    char padding[20];
    char property;
    void f(String value);
};

void S::f(String value)
{
    service->set(this ? &property : 0, value);
}
