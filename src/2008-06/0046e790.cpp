// from server: 100% by king_originala
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
        char storage[28];
    public:
        __forceinline ~basic_string();
    };
}

typedef std::basic_string<char, std::char_traits<char>,
                          std::allocator<char> > String;

extern void (__thiscall *destroyString)(String *);

namespace std {
    template<class T, class Traits, class Alloc>
    __forceinline basic_string<T, Traits, Alloc>::~basic_string()
    {
        destroyString(reinterpret_cast<String *>(this));
    }
}

struct Map {
    ~Map();
};

struct S {
    virtual ~S();
    String first;
    String second;
    String third;
    int value;
    Map map;
};

S::~S()
{
}
