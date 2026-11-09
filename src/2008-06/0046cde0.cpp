// from server: 100% by king_originala
extern void (__thiscall *string_construct)(void*, const char*);
extern void (__thiscall *string_destroy)(void*);

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
        unsigned char allocator_storage[4];
        union {
            T buffer[16];
            T* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

    public:
        basic_string(const T*);
        ~basic_string();
    };

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::basic_string(const T* text)
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

int __cdecl compare(const std::string&, const std::string&);

int __stdcall classify(std::string value)
{
    if (compare(value, std::string("symmetric")) == 0)
        return 0;
    if (compare(value, std::string("brick")) == 0)
        return 1;
    return 2;
}
