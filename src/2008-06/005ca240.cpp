// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern void (__thiscall *stringConstruct)(void*, const char*);
extern void (__thiscall *stringDestroy)(void*);

namespace std
{
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class C, class Traits, class Alloc>
    class basic_string
    {
        char allocatorStorage;
        union
        {
            C buffer[16];
            C* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

    public:
        basic_string(const C*);
        ~basic_string();
    };

    template<class C, class Traits, class Alloc>
    inline basic_string<C, Traits, Alloc>::basic_string(const C* text)
    {
        stringConstruct(this, text);
    }

    template<class C, class Traits, class Alloc>
    inline basic_string<C, Traits, Alloc>::~basic_string()
    {
        stringDestroy(this);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct RefCount
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;

    void release();
};

inline void RefCount::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

template<class T>
struct Shared
{
    T* object;
    RefCount* count;

    template<class U>
    Shared(const Shared<U>& other);
    ~Shared();
};

template<class T>
template<class U>
inline Shared<T>::Shared(const Shared<U>& other)
    : object(other.object), count(other.count)
{
    if (count)
        _InterlockedIncrement(&count->strong);
}

template<class T>
inline Shared<T>::~Shared()
{
    if (count)
        count->release();
}

struct Input
{
    char padding[0xc024];
    union
    {
        char buffer[16];
        char* pointer;
    } name;
    unsigned int length;
    unsigned int capacity;

    const char* c_str() const;
};

inline const char* Input::c_str() const
{
    if (capacity >= 16)
        return name.pointer;
    return name.buffer;
}

struct Item
{
    Item* f(Input*);
};

struct Node
{
    virtual void unused();
    virtual void setName(const std::string&);
    void attach(Item*);
};

struct TypedMemItem : Node {};

Shared<TypedMemItem> __cdecl create(Input*);

Item* Item::f(Input* input)
{
    Shared<Node> result(create(input));
    {
        std::string name(input->c_str());
        result.object->setName(name);
    }
    result.object->attach(this);
    return reinterpret_cast<Item*>(result.object);
}
