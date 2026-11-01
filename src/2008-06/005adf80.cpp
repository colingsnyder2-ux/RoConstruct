// from server: 100% by king_originala
struct String;
typedef void (__thiscall *StringFromText)(String *, const char *);
typedef void (__thiscall *StringCopy)(String *, const String &);
typedef void (__thiscall *StringDestroy)(String *);

extern StringFromText import_802458;
extern StringCopy import_80245c;
extern StringDestroy import_802468;

struct String
{
    void *proxy;
    union
    {
        char buffer[16];
        char *pointer;
    };
    unsigned length;
    unsigned capacity;

    String(const char *);
    String(const String &);
    ~String();
    const char *c_str() const;
};

inline String::String(const char *p)
{
    import_802458(this, p);
}

inline String::String(const String &s)
{
    import_80245c(this, s);
}

inline String::~String()
{
    import_802468(this);
}

inline const char *String::c_str() const
{
    const char *p = pointer;
    if (capacity < 16)
        p = buffer;
    return p;
}

struct Guid
{
    String text;
    const void *scope;
    ~Guid();
};

inline Guid::~Guid()
{
}

struct Name
{
    void sub_489810();
};

namespace RBX
{
    class Instance;
    class ServiceProvider
    {
    public:
        String sub_561e30(Guid);
    };
}

extern Name *__stdcall sub_493760(int, const char *);
extern const void *__cdecl sub_554270();
extern RBX::ServiceProvider *__cdecl func_00465210(RBX::Instance *);

extern "C" const char *__cdecl sub_611720(void *, int, void *, void *);
extern "C" int __cdecl sub_611c10(void *);
extern "C" void __cdecl sub_611c20(void *, int);
extern "C" RBX::Instance *__cdecl sub_612120(void *, int);
extern "C" void __cdecl sub_612410(void *, int);
extern "C" void __cdecl sub_612460(void *, int);
extern int __cdecl sub_611270(void *, const char *);
extern "C" void __cdecl sub_612b70(void *);
extern "C" void __cdecl sub_612920(void *, int, int);

inline RBX::Instance *getInstance(void *state)
{
    sub_612410(state, 67);
    sub_612460(state, -10002);
    RBX::Instance *instance = sub_612120(state, -1);
    sub_611c20(state, -2);
    return instance;
}

int __cdecl sub_5adf80(void *state)
{
    sub_493760(1, "dofile")->sub_489810();

    const char *text = sub_611720(state, 1, 0, 0);
    int top = sub_611c10(state);

    Guid guid = { String(text), sub_554270() };
    String result = func_00465210(getInstance(state))->sub_561e30(guid);

    if (sub_611270(state, result.c_str()))
        sub_612b70(state);

    sub_612920(state, 0, -1);
    return sub_611c10(state) - top;
}
