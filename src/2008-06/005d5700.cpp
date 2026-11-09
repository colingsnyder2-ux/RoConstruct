// from server: 100% by king_originala
struct String;
extern void (__thiscall *stringConstruct)(String*);
extern void (__thiscall *stringConstructText)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

struct String {
    char storage[28];
    String();
    String(const char*);
    ~String();
};

__forceinline String::String() { stringConstruct(this); }
__forceinline String::String(const char* text) { stringConstructText(this, text); }
__forceinline String::~String() { stringDestroy(this); }

struct Name;
extern const Name& __cdecl getLocalScope();

struct ScopedString {
    String text;
    const Name* scope;
    ScopedString(int = 0);
    ~ScopedString();
};

__forceinline ScopedString::ScopedString(int) : text(), scope(&getLocalScope()) {}
__forceinline ScopedString::~ScopedString() {}

struct Base {
    char storage[0x134];
    Base();
    ~Base();
    void setValue(const String&);
};

struct S : Base {
    ScopedString first;
    ScopedString second;
    void installTables();
    S();
};

__forceinline void S::installTables()
{
    unsigned char* p = reinterpret_cast<unsigned char*>(this);
    *reinterpret_cast<unsigned long*>(p + 0x000) = 0x83ca6c;
    *reinterpret_cast<unsigned long*>(p + 0x010) = 0x83ca60;
    *reinterpret_cast<unsigned long*>(p + 0x014) = 0x83ca58;
    *reinterpret_cast<unsigned long*>(p + 0x020) = 0x83ca50;
    *reinterpret_cast<unsigned long*>(p + 0x024) = 0x83ca40;
    *reinterpret_cast<unsigned long*>(p + 0x044) = 0x83ca30;
    *reinterpret_cast<unsigned long*>(p + 0x064) = 0x83ca20;
    *reinterpret_cast<unsigned long*>(p + 0x084) = 0x83ca10;
    *reinterpret_cast<unsigned long*>(p + 0x0a4) = 0x83ca00;
    *reinterpret_cast<unsigned long*>(p + 0x0c4) = 0x83c9f0;
    *reinterpret_cast<unsigned long*>(p + 0x130) = 0x83c9e8;
}

S::S() : Base(), first((installTables(), 0)), second()
{
    setValue(String("Clothing"));
}
