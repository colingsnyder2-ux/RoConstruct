// from server: 100% by king_originala
extern void (__thiscall *string_construct)(void *, const char *);
extern void (__thiscall *string_destroy)(void *);

namespace std {
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class T, class Traits, class Allocator>
    class basic_string {
        unsigned char storage[28];
    public:
        basic_string(const T *);
        ~basic_string();
    };

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::basic_string(const T *text)
    {
        string_construct(this, text);
    }

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::~basic_string()
    {
        string_destroy(this);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct Base {
    Base(const std::string &, int, const char *);
    virtual ~Base();
};

struct S : Base {
    S(int);
    virtual ~S();
};

S::S(int value)
    : Base(std::string("CanCollideVerb"), value, "CanCollide")
{
}
