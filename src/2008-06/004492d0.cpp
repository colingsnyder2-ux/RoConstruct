// from server: 100% by king_originala
struct String {
    char storage[28];
    String(const char *);
    ~String();
};

extern void (__thiscall *constructString)(String *, const char *);
extern void (__thiscall *destroyString)(String *);
extern bool (__cdecl *stringNotEqual)(const String &, const char *);

__forceinline String::String(const char *text)
{
    constructString(this, text);
}

__forceinline String::~String()
{
    destroyString(this);
}

extern const char *defaultText;
extern const float resetValue;

struct Manager;
typedef void (__thiscall *NotifyFunction)(Manager *, void *, const String &);

struct Manager {
    NotifyFunction *vtable;
};

extern Manager *manager;

struct S {
    char padding[0x158];
    String text;

    void reset(bool force);
    void setA(float);
    void setB(float);
    void setC(float);
    void setD(float);
};

void S::reset(bool force)
{
    if (force || stringNotEqual(text, defaultText)) {
        setA(resetValue);
        setB(resetValue);
        setA(resetValue);
        setC(resetValue);
        setD(resetValue);
        setC(resetValue);

        String value(defaultText);
        void *object = this ? reinterpret_cast<char *>(this) + 0x14 : 0;
        manager->vtable[3](manager, object, value);
    }
}
