// from server: 100% by king_originala
extern void (__thiscall *string_ctor)(void *);

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
        unsigned char storage[28];
    public:
        basic_string();
        ~basic_string();
    };

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::basic_string()
    {
        string_ctor(this);
    }
}

struct Primary {
    virtual void vf();
    unsigned char padding[0x70];
};

struct Secondary {
    virtual void vf();
    unsigned char padding0[0x18];
    int state;
    unsigned char padding1[0x78];
    unsigned int flags;
    unsigned char padding2[4];
};

struct Base : Primary, Secondary {
    Base(int, int, int);
    ~Base();
    void setFlags(unsigned int);
};

struct S : Base {
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > text;

    S(int, int, int);
    virtual void vf();
};

S::S(int a, int b, int c) : Base(a, b, c)
{
    state = 1;
    setFlags(flags | 0x01844013);
}
