// from server: 100% by king_originala
namespace std
{
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class T, class Traits, class Alloc>
    class basic_string
    {
        unsigned char allocator_storage[4];
        union
        {
            T buffer[16];
            T *pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

    public:
        basic_string(const T *);
        ~basic_string();
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class runtime_error
    {
        unsigned char storage[40];

    public:
        runtime_error(const string &);
        runtime_error(const runtime_error &);
        ~runtime_error();
    };
}

extern void (__thiscall *string_constructor)(std::string *, const char *);

namespace std
{
    template<>
    __forceinline basic_string<char, char_traits<char>, allocator<char> >::basic_string(const char *text)
    {
        string_constructor(this, text);
    }
}

extern "C" int *__cdecl sub_493760();

struct S
{
    unsigned char padding[0x1c8];
    volatile int active;

    void f(int, int);
};

void S::f(int, int)
{
    if (active && *sub_493760() == 2)
        throw std::runtime_error(std::string("Game script timout"));
}
