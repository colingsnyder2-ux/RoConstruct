// from server: 100% by king_originala
struct String;

typedef void (__thiscall *StringConstructor)(String *, const char *);
typedef void (__thiscall *StringDestructor)(String *);

extern StringConstructor stringConstructor;
extern StringDestructor stringDestructor;

struct String
{
    unsigned char storage[28];

    String(const char *text)
    {
        stringConstructor(this, text);
    }

    ~String()
    {
        stringDestructor(this);
    }
};

struct Base
{
    unsigned char storage[0x130];

    Base();
    ~Base();
    void setName(const String &);
};

struct Trackable
{
    unsigned long table;
    int first;
    int second;
    unsigned long third;

    Trackable() : first(-1), second(-1), third(0) {}
    ~Trackable();
};

extern unsigned long table0[];
extern unsigned long table10[];
extern unsigned long table14[];
extern unsigned long table20[];
extern unsigned long table24[];
extern unsigned long table44[];
extern unsigned long table64[];
extern unsigned long table84[];
extern unsigned long tableA4[];
extern unsigned long tableC4[];
extern unsigned long table130[];
extern const char detectorName[];

struct Detector : Base, Trackable
{
    unsigned long value;
    float distance;

    Detector();
};

Detector::Detector() : distance(32.0f)
{
    *reinterpret_cast<unsigned long **>(storage) = table0;
    *reinterpret_cast<unsigned long **>(storage + 0x10) = table10;
    *reinterpret_cast<unsigned long **>(storage + 0x14) = table14;
    *reinterpret_cast<unsigned long **>(storage + 0x20) = table20;
    *reinterpret_cast<unsigned long **>(storage + 0x24) = table24;
    *reinterpret_cast<unsigned long **>(storage + 0x44) = table44;
    *reinterpret_cast<unsigned long **>(storage + 0x64) = table64;
    *reinterpret_cast<unsigned long **>(storage + 0x84) = table84;
    *reinterpret_cast<unsigned long **>(storage + 0xA4) = tableA4;
    *reinterpret_cast<unsigned long **>(storage + 0xC4) = tableC4;
    table = reinterpret_cast<unsigned long>(table130);
    value = 0;
    String name(detectorName);
    setName(name);
}
