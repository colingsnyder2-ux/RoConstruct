// from server: 100% by king_originala
typedef void (__thiscall *StringConstruct)(void*, const char*);
typedef void (__thiscall *StringDestroy)(void*);

extern StringConstruct stringConstruct;
extern StringDestroy stringDestroy;

namespace std {
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class T, class Traits, class Alloc>
    class basic_string {
        Alloc alloc_;
        union {
            T buffer_[16];
            T* pointer_;
        };
        unsigned int size_;
        unsigned int capacity_;

    public:
        basic_string(const T*);
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::basic_string(const T* text)
    {
        stringConstruct(this, text);
    }

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::~basic_string()
    {
        stringDestroy(this);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct Instance;

struct Container {
    Instance* find(const std::string&);
};

struct Owner {
    char padding[0x21c];
    Container* container;
};

extern char instanceType;
extern char topMenuBarType;

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int
);

struct StatsCommand {
    char padding[0x0c];
    Owner* owner;
    bool execute();
};

bool StatsCommand::execute()
{
    Container* container = owner->container;
    std::string name("StatsHud1");
    return __RTDynamicCast(
        container->find(name), 0, &instanceType, &topMenuBarType, 0
    ) != 0;
}
