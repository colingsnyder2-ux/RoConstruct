// from server: 100% by king_originala
extern void (__thiscall *string_destructor)(void *);

struct String
{
    char storage[0x20];
    ~String();
};

inline String::~String()
{
    string_destructor(this);
}

struct Base
{
    char storage[0x134];
    ~Base();
};

struct S : Base
{
    String first;
    String second;
    ~S();
};

S::~S()
{
}
