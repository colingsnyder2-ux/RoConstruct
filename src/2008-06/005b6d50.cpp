// from server: 100% by king_originala
extern void (__thiscall *copy_string)(void*, const void*);

namespace std {
    template<class T> struct char_traits {};
    template<class T> struct allocator {};

    template<class T, class Traits, class Alloc>
    class basic_string {
        unsigned char allocatorStorage[4];
        union {
            T buffer[16 / sizeof(T)];
            T* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

    public:
        basic_string(const basic_string&);
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    __forceinline basic_string<T, Traits, Alloc>::basic_string(
        const basic_string& source)
    {
        copy_string(this, &source);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct Source {
    std::string text;
    int value;

    Source(const Source&);
};

__forceinline Source::Source(const Source& source)
    : text(source.text), value(source.value)
{
}

struct Base {
    virtual ~Base();
};

struct S : Base {
    Source data;

    S(const Source&);
    virtual ~S();
};

S::S(const Source& source)
    : data(source)
{
}
