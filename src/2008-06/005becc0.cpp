// from server: 100% by king_originala
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
    public:
        basic_string(const basic_string&);
        ~basic_string();
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern std::string* (__thiscall *copy_string)(
    std::string*, const std::string&);

namespace std {
    template<class T, class Traits, class Allocator>
    __forceinline basic_string<T, Traits, Allocator>::basic_string(
        const basic_string& source)
    {
        copy_string(this, source);
    }
}

struct S {
    const std::string& name() const;
};

std::string f(const S& source)
{
    return source.name();
}
