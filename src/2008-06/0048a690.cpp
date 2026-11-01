// from server: 100% by tester
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

typedef void (__thiscall *StringConstructor)(void*, const char*);
extern StringConstructor stringConstructor;

namespace std
{
    template<class T> struct char_traits {};
    template<class T> struct allocator {};

    template<class T, class Traits, class Alloc>
    class basic_string
    {
        Alloc alloc;
        union
        {
            T buffer[16];
            T* pointer;
        } storage;
        unsigned int length;
        unsigned int reserved;

    public:
        basic_string(const T*);
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    __forceinline basic_string<T, Traits, Alloc>::basic_string(const T* text)
    {
        stringConstructor(this, text);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class exception
    {
        char* message;
        int owned;

    public:
        virtual ~exception();
        virtual const char* what() const;
    };

    class runtime_error : public exception
    {
        string text;

    public:
        runtime_error(const string&);
        virtual ~runtime_error();
        virtual const char* what() const;
    };
}

namespace RBX
{
    class Instance
    {
    public:
        virtual ~Instance();
        void func_0055a8f0(Instance*);
    };

    class Accoutrement : public Instance {};
    class CharacterAppearance : public Instance {};
}

struct Control
{
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;
};

struct Pointer
{
    RBX::Instance* object;
    Control* control;

    ~Pointer();
};

__forceinline Pointer::~Pointer()
{
    Control* p = control;
    if (p)
    {
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

void func_0048a690(Pointer character, Pointer item)
{
    if (dynamic_cast<RBX::CharacterAppearance*>(item.object))
        item.object->func_0055a8f0(character.object);
    else if (dynamic_cast<RBX::Accoutrement*>(item.object))
        item.object->func_0055a8f0(character.object);
    else
    {
        std::string message(
            "Attempt to add a non-CharacterAppearance/Accoutrement object to a character");
        throw std::runtime_error(message);
    }
}
