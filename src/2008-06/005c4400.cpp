// from server: 100% by king_originala
namespace std {
template<class T> struct char_traits;
template<class T> class allocator;

template<class T, class Traits = char_traits<T>, class Alloc = allocator<T> >
class basic_string {
    unsigned int storage[7];
public:
    ~basic_string();
    basic_string& operator=(const basic_string&);
};

typedef basic_string<char> string;
}

extern std::string& (__thiscall *stringAssign)(std::string*, const std::string&);
extern void (__thiscall *stringDestroy)(std::string*);

namespace std {
template<class T, class Traits, class Alloc>
__forceinline basic_string<T, Traits, Alloc>::~basic_string()
{
    stringDestroy(this);
}

template<class T, class Traits, class Alloc>
__forceinline basic_string<T, Traits, Alloc>&
basic_string<T, Traits, Alloc>::operator=(const basic_string& value)
{
    return stringAssign(this, value);
}
}

struct Profiler {
    unsigned char padding[0x130];
    std::string name;

    void setName(std::string value);
};

void Profiler::setName(std::string value)
{
    name = value;
}
