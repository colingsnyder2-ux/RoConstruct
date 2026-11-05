// from server: 100% by king_originala
typedef unsigned int size_t;
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
        unsigned char storage[28];
    public:
        basic_string();
        ~basic_string();
        basic_string& operator=(const basic_string&);
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern std::string* (__thiscall *string_construct)(std::string*);
extern void (__thiscall *string_destroy)(std::string*);
extern std::string& (__thiscall *string_assign)(std::string*, const std::string&);

namespace std {
    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::basic_string()
    {
        string_construct(this);
    }

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::~basic_string()
    {
        string_destroy(this);
    }

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>&
    basic_string<T, Traits, Allocator>::operator=(const basic_string& value)
    {
        return string_assign(this, value);
    }
}

struct S;

struct OwnerStorage {
    S** pointer;
    explicit OwnerStorage(S* value);
    ~OwnerStorage();
};

inline OwnerStorage::OwnerStorage(S* value) : pointer(new S*(value)) {}
inline OwnerStorage::~OwnerStorage() { delete pointer; }

struct Owner : OwnerStorage {
    explicit Owner(S* value);
    ~Owner();
};

inline Owner::Owner(S* value) : OwnerStorage(value) {}
inline Owner::~Owner() {}

struct Storage {
    void* pointer;
    unsigned int unused;
    ~Storage();
};

inline Storage::~Storage()
{
    operator delete(pointer);
}

struct S {
    Owner owner;
    Storage unused;
    unsigned int first;
    unsigned int second;
    unsigned int third;
    std::string text;

    S(std::string value);
};

S::S(std::string value)
    : owner(this), first(0), second(0), third(0), text()
{
    text = value;
}
