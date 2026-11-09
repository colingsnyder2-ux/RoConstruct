// from server: 100% by king_originala
extern "C" void (__thiscall *string_destroy)(void *);

struct String {
    char storage[28];
    ~String();
};

__forceinline String::~String()
{
    string_destroy(this);
}

struct Base {
    char storage[36];
    ~Base();
};

struct S : Base {
    String text;
    ~S();
};

S::~S()
{
}
