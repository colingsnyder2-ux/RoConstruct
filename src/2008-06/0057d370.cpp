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
struct Input {
    unsigned char padding[0x1c8];
    unsigned char signal;
};
struct Base {
    Base(void*, std::string);
    virtual void slot();
};
struct S : Base {
    S(Input*);
    virtual void slot();
};
S::S(Input* input)
    : Base(input ? &input->signal : 0, "ForceAssertion")
{
}
