// from server: 61% by king_originala
struct String
{
    unsigned int proxy;
    char storage[16];
    unsigned int length;
    unsigned int capacity;
};

extern void (__thiscall *destroyString)(String *);
extern bool (__cdecl *callback)(const char *, const char *, int,
                                const String &, bool, int);
extern void (__cdecl *terminateProcess)(int);
extern void __cdecl releaseLog();
extern bool result;
extern const char *expression;
extern const char *filename;
extern int lineNumber;

struct Temporary
{
    unsigned int flags;
    String value;
    ~Temporary();
};

inline Temporary::~Temporary()
{
    if (flags & 1)
        destroyString(&value);
}

bool __cdecl check()
{
    bool terminate;
    {
        Temporary temporary;
        temporary.flags = 1;
        if (callback(expression, filename, lineNumber,
                     temporary.value, false, 1))
            terminate = true;
        else
            terminate = false;
    }
    if (terminate)
        terminateProcess(-1);
    releaseLog();
    return result;
}
