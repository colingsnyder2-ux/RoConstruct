// from server: 62% by king_originala
#pragma pointers_to_members(full_generality, multiple_inheritance)

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
        unsigned char storage[32];
    public:
        basic_string(const basic_string&);
    };
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

struct Resource {
    virtual ~Resource();
};

struct Guard {
    unsigned char prefix[4];
    Resource* volatile value;
    unsigned char storage[12];

    ~Guard() {
        Resource* p = value;
        if (p)
            delete p;
    }
};

struct S;

struct Object {
    void invoke(S*, const String&);
};

struct S {
    unsigned char padding[56];
    void (__thiscall Object::*callback)(String);
};

void Object::invoke(S* descriptor, const String& text)
{
    Guard guard;
    guard.value = reinterpret_cast<Resource*>(this);
    (this->*descriptor->callback)(text);
}
