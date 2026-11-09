// from server: 100% by king_originala
struct Text {
    char storage[28];
    Text(const char *);
    ~Text();
};

typedef void (__thiscall *TextConstructor)(Text *, const char *);
typedef void (__thiscall *TextDestructor)(Text *);

extern TextConstructor textConstructor;
extern TextDestructor textDestructor;

__forceinline Text::Text(const char *s)
{
    textConstructor(this, s);
}

__forceinline Text::~Text()
{
    textDestructor(this);
}

extern const char settingsName[];
extern const float defaultValue;
extern const unsigned long table344[];
extern const unsigned long table338[];
extern const unsigned long table330[];
extern const unsigned long table328[];
extern const unsigned long table318[];
extern const unsigned long table308[];
extern const unsigned long table2F8[];
extern const unsigned long table2E8[];
extern const unsigned long table2D8[];
extern const unsigned long table2C8[];

struct Base {
    unsigned char storage[0x130];
    Base();
    ~Base();
    void setName(const Text &);
};

struct S : Base {
    bool flag130;
    bool flag131;
    bool flag132;
    bool flag133;
    int value134;
    int value138;
    int value13C;
    bool flag140;
    bool flag141;
    bool flag142;
    bool flag143;
    int value144;
    int value148;
    int value14C;
    float value150;
    int value154;
    int value158;
    int value15C;

    S();
};

S::S() : Base(), value150(defaultValue)
{
    *reinterpret_cast<const unsigned long **>(storage) = table344;
    *reinterpret_cast<const unsigned long **>(storage + 0x10) = table338;
    *reinterpret_cast<const unsigned long **>(storage + 0x14) = table330;
    *reinterpret_cast<const unsigned long **>(storage + 0x20) = table328;
    *reinterpret_cast<const unsigned long **>(storage + 0x24) = table318;
    *reinterpret_cast<const unsigned long **>(storage + 0x44) = table308;
    *reinterpret_cast<const unsigned long **>(storage + 0x64) = table2F8;
    *reinterpret_cast<const unsigned long **>(storage + 0x84) = table2E8;
    *reinterpret_cast<const unsigned long **>(storage + 0xA4) = table2D8;
    *reinterpret_cast<const unsigned long **>(storage + 0xC4) = table2C8;

    flag130 = false;
    flag131 = false;
    flag132 = false;
    flag133 = false;
    value134 = 0;
    value138 = 1;
    value13C = 3000;
    flag140 = false;
    flag141 = false;
    flag142 = false;
    flag143 = false;
    value144 = -80;
    value148 = -200;
    value14C = 1;
    value154 = 0;
    value158 = 0;
    value15C = 0;

    Text name(settingsName);
    setName(name);
}
