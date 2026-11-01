// from server: 100% by king_originala
struct String;
typedef void (__thiscall *StringDestructor)(String *);
extern StringDestructor g_stringDestructor;

struct String
{
    char data[32];
    ~String();
};

inline String::~String()
{
    g_stringDestructor(this);
}

struct Setter
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void *, const String &);
};

extern Setter *g_setter;

struct S
{
    char padding[20];
    char value;

    void f(String text);
};

void S::f(String text)
{
    g_setter->set(this ? &value : 0, text);
}
