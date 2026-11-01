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
struct Base
{
    Base(std::string, int);
    virtual void v();
};
struct S : Base
{
    S(int, const char*);
    virtual void v();
};
S::S(int value, const char* text)
    : Base(std::string(text), value)
{
}
