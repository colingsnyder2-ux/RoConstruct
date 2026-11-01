// from server: 100% by king_originala
struct String;
extern String* (__thiscall *stringConstruct)(String*, const char*);
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

S::S()
{
    *reinterpret_cast<unsigned long*>(storage + 0x000) = 0x84356c;
    *reinterpret_cast<unsigned long*>(storage + 0x010) = 0x84355c;
    *reinterpret_cast<unsigned long*>(storage + 0x014) = 0x843554;
    *reinterpret_cast<unsigned long*>(storage + 0x020) = 0x84354c;
    *reinterpret_cast<unsigned long*>(storage + 0x024) = 0x84353c;
    *reinterpret_cast<unsigned long*>(storage + 0x044) = 0x84352c;
    *reinterpret_cast<unsigned long*>(storage + 0x064) = 0x84351c;
    *reinterpret_cast<unsigned long*>(storage + 0x084) = 0x84350c;
    *reinterpret_cast<unsigned long*>(storage + 0x0a4) = 0x8434fc;
    *reinterpret_cast<unsigned long*>(storage + 0x0c4) = 0x8434ec;
    *reinterpret_cast<unsigned long*>(storage + 0x130) = 0x8434d4;
    setValue(String("Hole"));
}
