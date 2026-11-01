// from server: 100% by colin
struct ErrorBase {
    ErrorBase();
    virtual void describe(char *, unsigned int, int);
    unsigned int reserved;
};

struct Error : ErrorBase {
    int code;
    virtual void describe(char *, unsigned int, int);
    ~Error();
};

inline Error::~Error()
{
}

struct String {
    char *data;
    __declspec(dllimport) String();
    __declspec(dllimport) ~String() throw();
};

extern void (__cdecl *stringFormat)(String *, const char *, ...);
extern const char *(__thiscall *stringData)(String *);





extern void __cdecl report(const char *, const char *);

void __cdecl reportError(const char *destination, int code,
                         const char *detail, const char *context)
{
    Error error;
    char buffer[1024];
    error.code = code;
    error.Error::describe(buffer, 1024, 0);

    String text;
    stringFormat(&text, "HRESULT = %d: %s\n%s(%d)", code, buffer, detail, context);
    report(destination, stringData(&text));
}
