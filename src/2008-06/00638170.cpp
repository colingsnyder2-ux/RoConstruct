// from server: 100% by king_originala
typedef void (__thiscall *StringConstructor)(void*, const char*);
typedef void (__thiscall *StringDestructor)(void*);

extern StringConstructor importedStringConstructor;
extern StringDestructor importedStringDestructor;

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class C, class T, class A>
    class basic_string {
        char storage[28];
    public:
        basic_string(const C*);
        ~basic_string();
    };

    template<class C, class T, class A>
    __forceinline basic_string<C, T, A>::basic_string(const C* text) {
        importedStringConstructor(this, text);
    }

    template<class C, class T, class A>
    __forceinline basic_string<C, T, A>::~basic_string() {
        importedStringDestructor(this);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct Base {
    unsigned int data[76];

    Base();
    ~Base();
    void setName(const std::string&);
};

struct S : Base {
    unsigned int value;

    S();
};

S::S() : Base() {
    data[0] = 0x0084930c;
    data[4] = 0x00849300;
    data[5] = 0x008492f8;
    data[8] = 0x008492f0;
    data[9] = 0x008492e0;
    data[17] = 0x008492d0;
    data[25] = 0x008492c0;
    data[33] = 0x008492b0;
    data[41] = 0x008492a0;
    data[49] = 0x00849290;
    value = 0;
    std::string name("Value");
    setName(name);
}
