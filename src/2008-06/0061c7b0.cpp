// from server: 100% by king_originala
extern void (__thiscall *Function00802458)(void*, const char*);

namespace std
{
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class T, class Traits, class Alloc>
    class basic_string
    {
        Alloc alloc;
        union
        {
            T buffer[16];
            T* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

    public:
        basic_string(const T*);
        basic_string(const basic_string&);
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::basic_string(const T* text)
    {
        Function00802458(this, text);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class exception
    {
        char* message;
        bool owned;

    public:
        exception(const exception&);
        virtual ~exception();
        virtual const char* what() const;
    };

    class runtime_error : public exception
    {
        string message;

    public:
        runtime_error(const string&);
        runtime_error(const runtime_error&);
        virtual ~runtime_error();
        virtual const char* what() const;
    };
}

extern "C" const char* __cdecl Function00612010(
    void*, int, unsigned int*);

const char* __cdecl Function0061c7b0(void* state, int index)
{
    const char* result = Function00612010(state, index, 0);
    if (!result)
    {
        std::string message("String expected");
        throw std::runtime_error(message);
    }
    return result;
}
