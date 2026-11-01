// from server: 100% by king_originala
typedef void (__thiscall *StringConstructor)(void*, const char*);
extern StringConstructor constructString;

namespace std {
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class C, class Traits, class Alloc>
    class basic_string {
        Alloc alloc;
        union {
            C buffer[16];
            C* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

    public:
        basic_string(const C*);
        basic_string(const basic_string&);
        ~basic_string();
    };

    template<class C, class Traits, class Alloc>
    inline basic_string<C, Traits, Alloc>::basic_string(const C* text)
    {
        constructString(this, text);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class exception {
        const char* message;
        int ownsMessage;

    public:
        exception();
        exception(const exception&);
        virtual ~exception();
        virtual const char* what() const;
    };

    class runtime_error : public exception {
        string text;

    public:
        runtime_error(const string&);
        runtime_error(const runtime_error&);
        virtual ~runtime_error();
        virtual const char* what() const;
    };
}

struct S {
    char padding[0x164];
    int active;

    void f();
};

void S::f()
{
    if (!active)
        throw std::runtime_error(std::string("This Mouse is no longer active"));
}
