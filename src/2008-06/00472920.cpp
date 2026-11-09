// from server: 100% by king_originala
extern void (__thiscall *string_destroy)(void *);
extern void (__thiscall *exception_destroy)(void *);

struct String {
    char storage[28];
    ~String();
};

struct Exception {
    unsigned vtable;
    char storage[8];
    ~Exception() throw();
};

struct Base : Exception {
    String text;
    ~Base() throw();
};

struct S : Base {
    String first;
    String second;
    ~S();
};

__forceinline String::~String()
{
    string_destroy(this);
}

__forceinline Exception::~Exception() throw()
{
    exception_destroy(this);
}

__forceinline Base::~Base() throw()
{
    vtable = 0x80b7f8;
}

S::~S()
{
}
