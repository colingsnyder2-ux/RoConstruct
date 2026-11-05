// from server: 100% by king_originala
struct Text;
extern void (__thiscall *text_construct)(Text *, const char *);
extern void (__thiscall *text_destroy)(Text *);

extern const unsigned long table000[];
extern const unsigned long table010[];
extern const unsigned long table014[];
extern const unsigned long table020[];
extern const unsigned long table024[];
extern const unsigned long table044[];
extern const unsigned long table064[];
extern const unsigned long table084[];
extern const unsigned long table0a4[];
extern const unsigned long table0c4[];
extern const unsigned long table130[];

struct Text {
    char storage[28];
    Text(const char *);
    ~Text();
};

__forceinline Text::Text(const char *s)
{
    text_construct(this, s);
}

__forceinline Text::~Text()
{
    text_destroy(this);
}

struct Base {
    unsigned char storage[0x134];
    Base();
    ~Base();
    void setName(const Text &);
};

struct State {
    int first;
    int second;
    int third;
    State();
    ~State();
};

__forceinline State::State()
{
    first = -1;
    second = -1;
    third = 0;
}

struct S : Base {
    State state;
    int value;
    int enabled;
    int active;
    int mode;
    S();
};

S::S() : Base(), state()
{
    *(const unsigned long **)(storage + 0x000) = table000;
    *(const unsigned long **)(storage + 0x010) = table010;
    *(const unsigned long **)(storage + 0x014) = table014;
    *(const unsigned long **)(storage + 0x020) = table020;
    *(const unsigned long **)(storage + 0x024) = table024;
    *(const unsigned long **)(storage + 0x044) = table044;
    *(const unsigned long **)(storage + 0x064) = table064;
    *(const unsigned long **)(storage + 0x084) = table084;
    *(const unsigned long **)(storage + 0x0a4) = table0a4;
    *(const unsigned long **)(storage + 0x0c4) = table0c4;
    *(const unsigned long **)(storage + 0x130) = table130;
    value = 0;
    enabled = 1;
    active = 1;
    mode = 2;
    setName(Text("Feature"));
}
