// from server: 100% by king_originala
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
        char storage[28];
    public:
        __declspec(dllimport) basic_string(const basic_string&);
        __declspec(dllimport) ~basic_string();
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct S {
    void f(std::string value);
};

void wrapper(S* object, std::string value)
{
    object->f(value);
}
