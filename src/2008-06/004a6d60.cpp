// from server: 100% by king_originala
struct String;
extern String* (__thiscall* stringDefaultConstruct)(String*);
extern void (__thiscall* stringDestroy)(String*);

struct String {
    char storage[28];
    String();
    ~String();
};

inline String::String()
{
    stringDefaultConstruct(this);
}

inline String::~String()
{
    stringDestroy(this);
}

extern void __cdecl makeString(const char*, String*);

struct Receiver {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void notify(int, const String&) = 0;
};

struct Context {
    Receiver* receiver;
    int value;
};

void __cdecl create(Context* context, const char* text)
{
    String string;
    makeString(text, &string);
    if (context->value)
        context->receiver->notify(context->value, string);
}
