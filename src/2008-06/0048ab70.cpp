// from server: 100% by king_originala
namespace std
{
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class C, class T, class A>
    class basic_string
    {
        unsigned int proxy;
        union
        {
            C buffer[16];
            C* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

    public:
        basic_string(const basic_string&);
        ~basic_string();
    };
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

extern String* (__thiscall *string_copy)(String*, const String&);
extern void (__thiscall *string_destroy)(String*);

namespace std
{
    template<class C, class T, class A>
    __forceinline basic_string<C, T, A>::basic_string(const basic_string& other)
    {
        string_copy(this, other);
    }

    template<class C, class T, class A>
    __forceinline basic_string<C, T, A>::~basic_string()
    {
        string_destroy(this);
    }
}

struct __multiple_inheritance Getter;

struct S
{
    unsigned int reserved[2];
    String (Getter::*getter)();

    String f(void* object);
};

String S::f(void* object)
{
    Getter* base = object
        ? reinterpret_cast<Getter*>(static_cast<char*>(object) - 20)
        : 0;
    return (base->*getter)();
}
