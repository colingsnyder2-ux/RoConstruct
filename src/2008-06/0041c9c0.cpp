// from server: 100% by king_originala
extern void (__thiscall *stringConstruct)(void*, const char*);
extern void (__thiscall *stringDestroy)(void*);

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
        unsigned char storage[28];
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

extern const unsigned char table0[];
extern const unsigned char table10[];
extern const unsigned char table14[];
extern const unsigned char table20[];
extern const unsigned char table24[];
extern const unsigned char table44[];
extern const unsigned char table64[];
extern const unsigned char table84[];
extern const unsigned char tableA4[];
extern const unsigned char tableC4[];

struct Base {
    unsigned int words[57];

    Base();
    ~Base();
    void setName(const std::string&);
};

struct S : Base {
    S();
};

S::S()
{
    words[0]  = reinterpret_cast<unsigned int>(table0);
    words[4]  = reinterpret_cast<unsigned int>(table10);
    words[5]  = reinterpret_cast<unsigned int>(table14);
    words[8]  = reinterpret_cast<unsigned int>(table20);
    words[9]  = reinterpret_cast<unsigned int>(table24);
    words[17] = reinterpret_cast<unsigned int>(table44);
    words[25] = reinterpret_cast<unsigned int>(table64);
    words[33] = reinterpret_cast<unsigned int>(table84);
    words[41] = reinterpret_cast<unsigned int>(tableA4);
    words[49] = reinterpret_cast<unsigned int>(tableC4);

    std::string name("WindowService");
    setName(name);
}
