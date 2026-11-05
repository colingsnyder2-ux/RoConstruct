// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace std {
template<class T> struct char_traits;
template<class T> class allocator;

template<class C, class T, class A>
class basic_string {
    unsigned char storage[28];
public:
    basic_string(const C*);
    __declspec(dllimport) basic_string(const basic_string&);
    ~basic_string();
};

typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern void (__thiscall *constructString)(void*, const char*);
extern void (__thiscall *copyString)(void*, const void*);
extern void (__thiscall *destroyString)(void*);

template<class C, class T, class A>
inline std::basic_string<C, T, A>::basic_string(const C* text)
{
    constructString(this, text);
}



template<class C, class T, class A>
inline std::basic_string<C, T, A>::~basic_string()
{
    destroyString(this);
}

extern const float initialValue;

struct Root {
    unsigned char storage[32];
    Root(std::string, int);
    virtual ~Root();
};

struct __declspec(novtable) ValueBase : Root {
    float value;
    ValueBase(const std::string&, int);
};

struct Base : ValueBase {
    Base(const std::string&, int);
    virtual ~Base();
};

struct S : Base {
    S(int);
    virtual ~S();
};

inline ValueBase::ValueBase(const std::string& name, int argument)
    : Root(name, argument), value(initialValue)
{
}

inline Base::Base(const std::string& name, int argument)
    : ValueBase(name, argument)
{
}

S::S(int argument)
    : Base(std::string("SelectionUpPlate"), argument)
{
}
