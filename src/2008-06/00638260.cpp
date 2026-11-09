// from server: 100% by king_originala
struct String;
extern void (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

struct String {
    char storage[28];

    String(const char* text) { stringConstruct(this, text); }
    ~String() { stringDestroy(this); }
};

struct Base {
    char storage[0x134];

    Base();
    ~Base();
    void setValue(const String&);
};

struct S : Base {
    S();
};

S::S() : Base()
{
    *reinterpret_cast<unsigned long*>(storage) = 0x8493cc;
    *reinterpret_cast<unsigned long*>(storage + 0x10) = 0x8493c0;
    *reinterpret_cast<unsigned long*>(storage + 0x14) = 0x8493b8;
    *reinterpret_cast<unsigned long*>(storage + 0x20) = 0x8493b0;
    *reinterpret_cast<unsigned long*>(storage + 0x24) = 0x8493a0;
    *reinterpret_cast<unsigned long*>(storage + 0x44) = 0x849390;
    *reinterpret_cast<unsigned long*>(storage + 0x64) = 0x849380;
    *reinterpret_cast<unsigned long*>(storage + 0x84) = 0x849370;
    *reinterpret_cast<unsigned long*>(storage + 0xa4) = 0x849360;
    *reinterpret_cast<unsigned long*>(storage + 0xc4) = 0x849350;
    storage[0x130] = 0;

    String value("Value");
    setValue(value);
}
