// from server: 100% by king_originala
extern void (__thiscall *stringConstruct)(void*);

namespace std {
template<class T> struct char_traits {};
template<class T> class allocator {};
template<class C, class T, class A> class basic_string {
    char storage[28];
public:
    basic_string();
    ~basic_string();
};

template<class C, class T, class A>
inline basic_string<C, T, A>::basic_string()
{
    stringConstruct(this);
}
}

extern int primaryTable[];
extern int secondaryTable[];

struct Base {
    int storage[7];
    int f(int);
    Base(int);
    ~Base();
};

inline Base::Base(int a)
{
    f(a);
    storage[0] = (int)primaryTable;
    storage[1] = (int)secondaryTable;
    ((int*)this)[7] = 0;
}

struct Pair {
    int first;
    int second;
    Pair(void*);
    ~Pair();
};

inline Pair::Pair(void*)
{
    second = 0;
}

struct S : Base {
    Pair pair;
    int value;
    int unused;
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > text;
    S(int);
};

S::S(int a) : Base(a), pair(this), value(0), text()
{
}
