// from server: 100% by king_originala
extern void (__thiscall *constructString)(void*, const char*);

namespace std
{
    template<class T> struct char_traits {};
    template<class T> struct allocator {};

    template<class T, class Traits, class Allocator>
    class basic_string
    {
        unsigned int allocatorState;
        union
        {
            T buffer[16];
            T* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

    public:
        basic_string(const T*);
        ~basic_string();
    };

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::basic_string(const T* text)
    {
        constructString(this, text);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class exception
    {
        char* message;
        bool ownsMessage;

    public:
        virtual ~exception();
        virtual const char* what() const;
    };

    class runtime_error : public exception
    {
        string message;

    public:
        explicit runtime_error(const string&);
        virtual ~runtime_error();
        virtual const char* what() const;
    };
}

struct Appearance
{
    void remove(void (__cdecl*)());
};

struct Object
{
    unsigned char padding[0x170];
    Appearance* appearance;

    void removeCharacterAppearance();
};

extern bool __cdecl checkBackend(int, int);
extern void __cdecl removeAppearance();

void Object::removeCharacterAppearance()
{
    if (!checkBackend(reinterpret_cast<int>(this), 1))
    {
        std::string text(
            "RemoveCharacterAppearance can only be called by the backend server");
        throw std::runtime_error(text);
    }

    if (appearance)
        appearance->remove(removeAppearance);
}
