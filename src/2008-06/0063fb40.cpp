// from server: 100% by king_originala
extern void (__thiscall *destroy_string)(void*);

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
        union {
            T buffer[16];
            T* pointer;
        };
        unsigned int length;
        unsigned int capacity;
    public:
        ~basic_string();
    };

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::~basic_string()
    {
        destroy_string(this);
    }
}

struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct Base : Primary, Secondary {
    char storage[20];
    virtual ~Base();
};

struct GrabTool : Base {
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > text;
    virtual ~GrabTool();
};

GrabTool::~GrabTool()
{
}
