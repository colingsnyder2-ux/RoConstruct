// from server: 100% by king_originala
struct String
{
    char storage[28];
    String(const char *);
    ~String();
};

struct Error
{
    char storage[40];
    Error(const String &);
    Error(const Error &);
    ~Error();
};

struct Source
{
    virtual void destroy(unsigned int) = 0;
    virtual const char *message() = 0;
};

extern Source *globalSource;

extern void (__thiscall *stringConstruct)(String *, const char *);
extern void (__thiscall *stringDestroy)(String *);

inline String::String(const char *text)
{
    stringConstruct(this, text);
}

inline String::~String()
{
    stringDestroy(this);
}

void func_0044ab30()
{
    if (globalSource)
    {
        Error error(String(globalSource->message()));
        Source *source = globalSource;
        globalSource = 0;
        if (source)
            source->destroy(1);
        throw error;
    }
}
