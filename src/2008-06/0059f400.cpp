// from server: 100% by king_originala
extern void (__thiscall *destroy_string)(void*);

namespace std
{
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class T, class Traits, class Alloc>
    class basic_string
    {
        char storage[32];
    public:
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::~basic_string()
    {
        destroy_string(this);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct Value
{
    std::string get();
};

struct Setter
{
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void set(void*, const std::string&) = 0;
};

struct S
{
    char padding[24];
    Setter* setter;

    void f(void*, Value*);
};

void S::f(void* object, Value* value)
{
    Setter* target = setter;
    target->set(object, value->get());
}
