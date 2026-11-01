// from server: 100% by colin

extern "C" void * (__cdecl *malloc)(unsigned int);

inline void * __cdecl operator new(unsigned int size)
{
    return malloc(size);
}

void __cdecl operator delete(void *);

struct String;
extern void (__thiscall *string_construct)(String *, const char *);
extern void (__thiscall *string_destroy)(String *);

struct String {
    unsigned char storage[28];
    String(const char *);
    ~String();
};

inline String::String(const char *text)
{
    string_construct(this, text);
}

inline String::~String()
{
    string_destroy(this);
}

struct Widget {
    unsigned char storage[0x1a4];
    Widget(const String &, const String &);
};

struct Empty {};

struct Result {
    void *object;
    void *control;
    Result(Widget *, Empty = Empty());
    ~Result();
};

Result makeWidget(const char *first, const char *second)
{
    return Result(new Widget(String(first), String(second)));
}
