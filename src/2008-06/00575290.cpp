// from server: 68% by king_originala
extern void (__thiscall *string_construct)(void*, const char*);

namespace std {
    template<class T> struct char_traits {};
    template<class T> struct allocator {};

    template<class T, class Traits, class Alloc>
    class basic_string {
        unsigned char storage[28];
    public:
        basic_string(const T*);
        basic_string(const basic_string&);
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::basic_string(const T* value)
    {
        string_construct(this, value);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class exception {
        const char* message;
        int owned;
    public:
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
    };
}

struct Verb {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void execute(void*) = 0;
};

struct VerbContainer {
    Verb* find(std::string);
};

struct ServiceProvider {
    unsigned char padding[0x1c8];
    VerbContainer verbs;
    void exit();
};

void ServiceProvider::exit()
{
    Verb* verb = verbs.find(std::string("Exit"));
    if (!verb)
        throw std::runtime_error(std::string("Couldn't find Exit Verb"));
    verb->execute(0);
}
