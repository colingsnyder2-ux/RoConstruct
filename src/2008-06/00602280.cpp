// from server: 100% by king_originala
extern "C" void* (__cdecl *malloc_call)(unsigned int);

inline void* __cdecl operator new(unsigned int size)
{
    return malloc_call(size);
}

void __cdecl operator delete(void*);

struct String {
    char storage[28];
    String(const char*);
    ~String();
};

extern void (__thiscall *string_construct)(String*, const char*);
extern void (__thiscall *string_destroy)(String*);

inline String::String(const char* text)
{
    string_construct(this, text);
}

inline String::~String()
{
    string_destroy(this);
}

struct S {
    char storage[384];
    S(int, const String&);
};

struct Tag {
    char value;
    Tag();
};

inline Tag::Tag() : value(0)
{
}

struct Result {
    Result(S*, Tag);
    ~Result();
};

Result __cdecl make(int a, const char* text)
{
    Tag tag;
    return Result(new S(a, String(text)), tag);
}
