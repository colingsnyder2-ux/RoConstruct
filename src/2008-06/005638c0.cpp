// from server: 100% by colin
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
        char storage[28];
    public:
        basic_string(const basic_string&);
        ~basic_string();
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern void (__thiscall *copy_string)(void*, const void*);

template<class T, class Traits, class Alloc>
__forceinline std::basic_string<T, Traits, Alloc>::basic_string(
    const std::basic_string<T, Traits, Alloc>& source)
{
    copy_string(this, &source);
}

struct S {
    char prefix[0x48];
    std::string text;
    char suffix[0x20];

    S();
    ~S();
};

std::string __stdcall f()
{
    return S().text;
}
