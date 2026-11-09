// from server: 100% by king_originala
extern "C" {
    extern void (__thiscall *stringConstruct)(void*, const char*);
    extern void (__thiscall *stringDestroy)(void*);
}

namespace std {
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class T, class Traits, class Allocator>
    class basic_string {
        char storage[28];
    public:
        basic_string(const T*);
        ~basic_string();
    };

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::basic_string(const T* text)
    {
        stringConstruct(this, text);
    }

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::~basic_string()
    {
        stringDestroy(this);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern char instanceType[];
extern char partInstanceType[];

extern "C" void* __cdecl dynamicCast(
    void*, long, void*, void*, int);

struct Instance {
    void* findChild(const std::string&);
};

struct Humanoid {
    char padding[0x104];
    Instance* instance;
    void* getTorso();
};

void* Humanoid::getTorso()
{
    std::string name("Torso");
    return dynamicCast(
        instance->findChild(name),
        0,
        instanceType,
        partInstanceType,
        0);
}
