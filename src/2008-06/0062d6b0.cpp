// from server: 100% by king_originala
typedef void (__thiscall *StringConstructor)(void *, const char *);
typedef void (__thiscall *StringDestructor)(void *);

extern StringConstructor stringConstructor;
extern StringDestructor stringDestructor;
extern const char name_84686c[];

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
        unsigned char storage[28];
    public:
        basic_string(const T *);
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::basic_string(const T *text)
    {
        stringConstructor(this, text);
    }

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::~basic_string()
    {
        stringDestructor(this);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern unsigned int table_84682c[];
extern unsigned int table_846820[];
extern unsigned int table_846818[];
extern unsigned int table_846810[];
extern unsigned int table_846800[];
extern unsigned int table_8467f0[];
extern unsigned int table_8467e0[];
extern unsigned int table_8467d0[];
extern unsigned int table_8467c0[];
extern unsigned int table_8467b0[];
extern unsigned int table_846798[];

struct Base {
    unsigned char storage[0x130];
    Base();
    ~Base();
    void setName(const std::string &);
};

struct Counter {
    unsigned int table;
    int first;
    int second;
    int third;
    Counter();
    ~Counter();
};

inline Counter::Counter() : first(-1), second(-1), third(0)
{
}

struct S : Base {
    Counter counter;
    unsigned char enabled;
    unsigned char padding[3];
    int value;
    S();
};

S::S()
{
    *reinterpret_cast<unsigned int *>(storage + 0x00) =
        reinterpret_cast<unsigned int>(table_84682c);
    *reinterpret_cast<unsigned int *>(storage + 0x10) =
        reinterpret_cast<unsigned int>(table_846820);
    *reinterpret_cast<unsigned int *>(storage + 0x14) =
        reinterpret_cast<unsigned int>(table_846818);
    *reinterpret_cast<unsigned int *>(storage + 0x20) =
        reinterpret_cast<unsigned int>(table_846810);
    *reinterpret_cast<unsigned int *>(storage + 0x24) =
        reinterpret_cast<unsigned int>(table_846800);
    *reinterpret_cast<unsigned int *>(storage + 0x44) =
        reinterpret_cast<unsigned int>(table_8467f0);
    *reinterpret_cast<unsigned int *>(storage + 0x64) =
        reinterpret_cast<unsigned int>(table_8467e0);
    *reinterpret_cast<unsigned int *>(storage + 0x84) =
        reinterpret_cast<unsigned int>(table_8467d0);
    *reinterpret_cast<unsigned int *>(storage + 0xa4) =
        reinterpret_cast<unsigned int>(table_8467c0);
    *reinterpret_cast<unsigned int *>(storage + 0xc4) =
        reinterpret_cast<unsigned int>(table_8467b0);
    counter.table = reinterpret_cast<unsigned int>(table_846798);
    enabled = 0;
    value = 0;

    std::string name(name_84686c);
    setName(name);
}
