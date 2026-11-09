// from server: 100% by king_originala
namespace std {
template<class T> struct char_traits {};
template<class T> struct allocator {};

template<class C, class Traits, class Alloc>
class basic_string {
    Alloc alloc;
    union {
        C buffer[16];
        C* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
public:
    ~basic_string();
};

typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern "C" void (__cdecl* _invalid_parameter_noinfo)();
extern void (__thiscall* string_destroy)(std::string*);

namespace std {
template<class C, class Traits, class Alloc>
inline basic_string<C, Traits, Alloc>::~basic_string()
{
    string_destroy(this);
}
}

struct Item {
    virtual ~Item();
};

struct Holder {
    Item* value;
    Item** get(const std::string&);
};

struct Owner {
    unsigned int prefix[3];
    Item** first;
    Item** last;
    Item** limit;

    Owner(unsigned int);
    ~Owner();
};

struct Service {
    virtual void unused();
    virtual void apply(Owner&);
};

struct S {
    Service* service;
    void f(std::string text);
};

void S::f(std::string text)
{
    Owner owner(1);
    if (static_cast<unsigned int>(owner.last - owner.first) <= 0U)
        _invalid_parameter_noinfo();

    {
        Holder holder;
        Item** first = owner.first;
        Item** value = holder.get(text);
        if (value != first) {
            Item* temporary = *value;
            *value = *first;
            *first = temporary;
        }
        if (holder.value)
            delete holder.value;
    }

    service->apply(owner);
}
