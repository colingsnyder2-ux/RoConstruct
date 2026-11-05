// from server: 100% by king_originala
extern void (__thiscall *destroy_string)(void*);

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class C, class T, class A>
    class basic_string {
        unsigned char storage[28];
    public:
        ~basic_string();
    };

    template<class C, class T, class A>
    inline basic_string<C, T, A>::~basic_string()
    {
        destroy_string(this);
    }
}

struct Element {
    unsigned char prefix[8];
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > first;
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > second;
};

void __cdecl destroy_elements(Element* first, Element* last)
{
    for (; first != last; ++first)
        first->~Element();
}
