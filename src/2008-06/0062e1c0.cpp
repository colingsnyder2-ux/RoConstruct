// from server: 100% by king_originala
struct String;
typedef void (__thiscall *StringConstructor)(String *, const char *);
extern StringConstructor constructString;

struct String
{
    unsigned char storage[28];
    String(const char *);
    ~String();
};

inline String::String(const char *text)
{
    constructString(this, text);
}

struct Error
{
    unsigned char storage[40];
    Error(const String &);
};

extern unsigned char errorType;
extern "C" __declspec(noreturn) void __stdcall
ThrowError(void *, void *);

struct S
{
    unsigned char padding[0x148];
    bool fired;
    void fire();
};

extern int __cdecl isInWorkspace(S *);
extern bool __cdecl isClient(S *, int);

void S::fire()
{
    if (!isInWorkspace(this))
    {
        String message("Rocket:Fire may only be called when the Rocket is in the Workspace");
        Error error(message);
        ThrowError(&error, &errorType);
    }

    if (isClient(this, 1))
    {
        String message("Rocket:Fire may not be called from a client");
        Error error(message);
        ThrowError(&error, &errorType);
    }

    fired = true;
}
