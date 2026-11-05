// from server: 100% by tester
struct String;
extern void (__thiscall *string_destroy)(String *);

struct String
{
    char storage[28];
    ~String();
};

inline String::~String()
{
    string_destroy(this);
}

struct Base
{
    char storage[0x148];
    ~Base();
};

struct S : Base
{
    String value;
    ~S();
};

S::~S()
{
}
