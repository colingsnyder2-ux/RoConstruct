// from server: 100% by king_originala
extern void (__thiscall* string_destructor)(void*);

namespace std
{
    template<class T> struct char_traits {};
    template<class T> struct allocator {};

    template<class C, class T, class A>
    class basic_string
    {
        char data[28];
    public:
        ~basic_string();
    };

    template<class C, class T, class A>
    inline basic_string<C, T, A>::~basic_string()
    {
        string_destructor(this);
    }
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > Value;

struct Managed
{
    virtual ~Managed();
};

struct Holder
{
    Managed* value;
    Holder(const Value&);
    ~Holder();
    void swap(Managed*&);
};

inline Holder::~Holder()
{
    if (value)
        delete value;
}

inline void Holder::swap(Managed*& other)
{
    if (&value != &other)
    {
        Managed* old = value;
        value = other;
        other = old;
    }
}

inline void assignValue(Managed*& destination, const Value& source)
{
    Holder(source).swap(destination);
}

struct Getter
{
    virtual void slot0();
    virtual void slot1();
    virtual Value get(void*);
};

extern void* __cdecl func_00615490();

struct Result
{
    void* type;
    Managed* value;
    void set(const Value&);
};

inline void Result::set(const Value& source)
{
    type = func_00615490();
    assignValue(value, source);
}

struct S
{
    char padding[24];
    Getter* getter;
    void func_0059f280(void*, Result*);
};

void S::func_0059f280(void* object, Result* result)
{
    result->set(getter->get(object));
}
