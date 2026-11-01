// from server: 100% by colin
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;
    template<class T, class Traits, class Alloc>
    class __declspec(dllimport) basic_string {
        char storage[28];
    public:
        basic_string(const T*);
        basic_string(const basic_string&);
        ~basic_string();
    };
    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}



struct ExceptionObject {
    unsigned long words[10];

    ExceptionObject();
    ~ExceptionObject();
};

extern __declspec(noreturn) void __cdecl raise_exception(const void*);

struct Dispatch {
    void* reserved;
    void (__cdecl *invoke)(void*, std::string, int);
};

struct S {
    Dispatch* dispatch;
    unsigned long reserved;
    unsigned char object[1];

    void invoke(std::string value, int argument);
};

void S::invoke(std::string value, int argument)
{
    if (!dispatch)
        raise_exception(&ExceptionObject());

    dispatch->invoke(object, value, argument);
}
