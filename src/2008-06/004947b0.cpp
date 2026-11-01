// from server: 100% by king_originala
extern void (__thiscall *stringConstruct)(void*, const char*);

namespace std {
template<class T> struct char_traits {};
template<class T> struct allocator {};

template<class T, class Traits, class Alloc>
class basic_string {
    unsigned char allocator_storage[4];
    union {
        T buffer[16];
        T* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
public:
    basic_string(const T*);
    basic_string(const basic_string&);
    ~basic_string();
};

template<class T, class Traits, class Alloc>
inline basic_string<T, Traits, Alloc>::basic_string(const T* s)
{
    stringConstruct(this, s);
}

typedef basic_string<char, char_traits<char>, allocator<char> > string;

class exception {
    const char* message;
    bool owns_message;
public:
    exception(const exception&);
    virtual ~exception();
    virtual const char* what() const;
};

class runtime_error : public exception {
    string text;
public:
    runtime_error(const string&);
    runtime_error(const runtime_error&);
    virtual ~runtime_error();
};
}

struct Player {
    void removeCharacter();
    void setCharacter(int);
};

extern bool __cdecl checkBackend(Player*, int);

void Player::removeCharacter()
{
    if (!checkBackend(this, 1))
        throw std::runtime_error(
            std::string("RemoveCharacter can only be called by the backend server"));
    setCharacter(0);
}
