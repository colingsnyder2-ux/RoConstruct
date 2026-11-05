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
typedef void* (__thiscall *StringCopy)(void*, const void*);
extern StringCopy string_copy;



struct Tail {
    Tail(const Tail&);
};

struct SignalDesc {
    unsigned int first;
    unsigned int second;
    std::string name;
    Tail tail;

    SignalDesc(const SignalDesc&);
};

SignalDesc::SignalDesc(const SignalDesc& other)
    : first(other.first),
      second(other.second),
      name(other.name),
      tail(other.tail)
{
}
