// from server: 100% by king_originala
typedef void (__thiscall *StringCopy)(void*, const void*);
typedef void (__thiscall *StringDestroy)(void*);

extern StringCopy string_copy;
extern StringDestroy string_destroy;

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
        char storage[28];
    public:
        basic_string(const basic_string&);
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::basic_string(const basic_string& other)
    {
        string_copy(this, &other);
    }

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::~basic_string()
    {
        string_destroy(this);
    }
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

struct S {
    String text;
    bool flag;

    S(String value, bool enabled);
};

S::S(String value, bool enabled)
    : text(value), flag(enabled)
{
}
