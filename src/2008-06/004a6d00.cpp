// from server: 100% by king_originala
extern void (__thiscall *destroyString)(void *);

namespace std {
    template<class T> struct char_traits {};
    template<class T> struct allocator {};

    template<class T, class Traits, class Alloc>
    class basic_string {
        unsigned char storage[28];
    public:
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::~basic_string()
    {
        destroyString(this);
    }
}

typedef std::basic_string<char, std::char_traits<char>,
                         std::allocator<char> > String;

struct Source {
    String get();
};

extern void __cdecl consume(void *, const String &);

void __cdecl reconstruct(Source *source, void *destination)
{
    consume(destination, source->get());
}
