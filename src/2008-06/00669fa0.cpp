// from server: 100% by king_originala
struct LocaleImpl;

extern LocaleImpl* (__cdecl* getGlobalLocale)();
extern LocaleImpl* (__cdecl* initLocale)();
extern void (__thiscall* increfLocale)(LocaleImpl*);
extern void (__thiscall* destroyLocale)(void*);
extern void (__thiscall* destroyString)(void*);
extern void (__cdecl* invalidParameter)();

struct Locale
{
    LocaleImpl* impl;
    unsigned char storage[4];

    Locale();
    ~Locale();
};

struct String
{
    unsigned char data[28];

    ~String();
};

struct Iterator
{
    void* owner;
    void* node;
};

extern void __cdecl prepareString(String*, Locale*);

struct TreeStage
{
    void* owner;
    unsigned char padding[20];
    void* endNode;

    Iterator* lookup(Iterator*, const String*);
    bool process(String);
};

__forceinline Locale::Locale()
{
    impl = getGlobalLocale();
    increfLocale(initLocale());
}

__forceinline Locale::~Locale()
{
    destroyLocale(this);
}

__forceinline String::~String()
{
    destroyString(this);
}

bool TreeStage::process(String value)
{
    Iterator* result;
    {
        Locale locale;
        prepareString(&value, &locale);
        result = reinterpret_cast<Iterator*>(&locale);
    }

    void* savedEnd = endNode;
    void* savedOwner = owner;
    Iterator* found = lookup(result, &value);

    if (!found->owner || found->owner != savedOwner)
        invalidParameter();

    return found->node != savedEnd;
}
