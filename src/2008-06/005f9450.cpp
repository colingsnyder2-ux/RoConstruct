// from server: 100% by colin
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
        char storage[28];
    public:
        basic_string(const T*);
        ~basic_string();
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern void* (__thiscall *StringConstruct)(void*, const char*);

template<>
__forceinline std::basic_string<char, std::char_traits<char>,
    std::allocator<char> >::basic_string(const char* text)
{
    StringConstruct(this, text);
}

struct ReadError {
    char storage[40];
    ReadError(const std::string&);
    ReadError(const ReadError&);
    ~ReadError();
};

extern "C" {
    extern int (__stdcall *InternetQueryDataAvailable)(
        void*, unsigned long*, unsigned long, unsigned long);
    extern int (__stdcall *InternetReadFile)(
        void*, void*, unsigned long, unsigned long*);
}

struct Input {
    void* handle;
    long read(char*, long);
};

long Input::read(char* buffer, long count)
{
    unsigned long available;
    unsigned long received;

    if (!InternetQueryDataAvailable(handle, &available, 0, 0))
        goto fail;

    if (available == 0)
        goto fail;

    if (!InternetReadFile(handle, buffer, count, &received)) {
        std::string message("InternetReadFile failed");
        throw ReadError(message);
    }

    return received;

fail:
    return -1;
}
