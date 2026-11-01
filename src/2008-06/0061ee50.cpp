// from server: 100% by king_originala
extern "C" int __cdecl strcmp(const char *, const char *);
#pragma intrinsic(strcmp)

struct String
{
    unsigned int proxy;
    union
    {
        char buffer[16];
        char *pointer;
    };
    unsigned int length;
    unsigned int capacity;

    ~String();
};

struct Error
{
    char storage[40];

    Error(const String &);
    Error(const Error &);
    ~Error();
};

extern String __cdecl Function00509b10(const char *, ...);
extern "C" void __cdecl Function00612280(void *, const char *);
extern "C" void __cdecl Function00612200(void *, double);

int __cdecl Function0061ee50(void **object, const char *name, void *state)
{
    if (strcmp(name, "Name") == 0)
    {
        String *text = (String *)((char *)*(void **)((char *)*object + 4) + 4);
        Function00612280(state, text->capacity >= 16 ? text->pointer : text->buffer);
        return 1;
    }

    if (strcmp(name, "Value") == 0)
    {
        Function00612200(state, (double)*(int *)((char *)*object + 12));
        return 1;
    }

    throw Error(Function00509b10("%s is not a valid member", name));
}
