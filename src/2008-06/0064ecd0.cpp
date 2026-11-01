// from server: 100% by king_originala
extern void (__thiscall *string_destructor)(void *);

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
        char storage[28];
    public:
        ~basic_string();
    };

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::~basic_string()
    {
        string_destructor(this);
    }
}

struct VerbWidget {
    char storage[0x14c];
    ~VerbWidget();
};

struct MenuItem : VerbWidget {
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > text;
    ~MenuItem();
};

MenuItem::~MenuItem()
{
}
