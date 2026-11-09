// from server: 100% by king_originala
extern void (__thiscall *destroy_string)(void*);

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
        char storage[28];
    public:
        ~basic_string();
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    template<class T, class Traits, class Alloc>
    __forceinline basic_string<T, Traits, Alloc>::~basic_string()
    {
        destroy_string(this);
    }
}

struct S {
    char prefix[16];
    std::string first;
    std::string second;
    std::string third;
    char gap[4];
    std::string fourth;

    ~S();
};

S::~S()
{
}
