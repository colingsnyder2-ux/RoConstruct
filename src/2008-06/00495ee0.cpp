// from server: 100% by king_originala
extern void (__thiscall *destroy_string)(void *);

struct String
{
    char storage[28];
    ~String();
};

__forceinline String::~String()
{
    destroy_string(this);
}

struct S
{
    int prefix;
    String first;
    String second;
    ~S();
};

S::~S()
{
}
