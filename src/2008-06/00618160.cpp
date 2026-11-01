// from server: 100% by king_originala
typedef void (__thiscall *StringConstructor)(void*, const char*);
extern StringConstructor stringConstructor;

namespace std {
template<class T> struct char_traits {};
template<class T> struct allocator {};

template<class T, class Traits, class Alloc>
class basic_string {
    char storage[28];
public:
    basic_string(const T*);
    ~basic_string();
};

template<class T, class Traits, class Alloc>
__forceinline basic_string<T, Traits, Alloc>::basic_string(const T* text)
{
    stringConstructor(this, text);
}
}

extern const int table0[];
extern const int table1[];

struct S_func_006159f0 {
    char storage[28];
    int f(int a1);
    S_func_006159f0(int a1);
    ~S_func_006159f0();
};

__forceinline S_func_006159f0::S_func_006159f0(int a1)
{
    f(a1);
}

struct S : S_func_006159f0 {
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > cursor;
    volatile bool flag;
    volatile float x;
    volatile float y;
    volatile float z;
    S(int a1);
};

S::S(int a1)
    : S_func_006159f0(a1),
      cursor((*(const int**)this = table0,
              *((const int**)this + 1) = table1,
              "ArrowCursor"))
{
    flag = false;
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}
