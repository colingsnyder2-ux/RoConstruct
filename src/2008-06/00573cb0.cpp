// from server: 100% by colin
struct Color {
    float r, g, b, a;
    Color() {}
    Color(float);
    Color& operator=(const Color& other) { r=other.r; g=other.g; b=other.b; a=other.a; return *this; }
};

__forceinline Color::Color(float v) : r(v), g(v), b(v), a(v) {}

extern const Color& __cdecl zeroColor();
extern const float whiteValue;

extern const unsigned long table00Data[];
extern const unsigned long table10Data[];
extern const unsigned long table14Data[];
extern const unsigned long table20Data[];
extern const unsigned long table24Data[];
extern const unsigned long table44Data[];
extern const unsigned long table64Data[];
extern const unsigned long table84Data[];
extern const unsigned long tableA4Data[];
extern const unsigned long tableC4Data[];
extern const unsigned long table130Data[];

struct PercentPanel {
    unsigned long table00;
    char pad04[12];
    unsigned long table10;
    unsigned long table14;
    char pad18[8];
    unsigned long table20;
    unsigned long table24;
    char pad28[28];
    unsigned long table44;
    char pad48[28];
    unsigned long table64;
    char pad68[28];
    unsigned long table84;
    char pad88[28];
    unsigned long tableA4;
    char padA8[28];
    unsigned long tableC4;
    char padC8[104];
    unsigned long table130;
    char pad134[16];

    PercentPanel();
    ~PercentPanel();
    void setName(const char*);
};

struct GuiRoot : PercentPanel {
    Color backdropColor;
    void* owner;
    bool enabled;

    GuiRoot(const char*, void*, bool);
};

GuiRoot::GuiRoot(const char* name, void* parent, bool white)
    : PercentPanel()
{
    table00 = reinterpret_cast<unsigned long>(table00Data);
    table10 = reinterpret_cast<unsigned long>(table10Data);
    table14 = reinterpret_cast<unsigned long>(table14Data);
    table20 = reinterpret_cast<unsigned long>(table20Data);
    table24 = reinterpret_cast<unsigned long>(table24Data);
    table44 = reinterpret_cast<unsigned long>(table44Data);
    table64 = reinterpret_cast<unsigned long>(table64Data);
    table84 = reinterpret_cast<unsigned long>(table84Data);
    tableA4 = reinterpret_cast<unsigned long>(tableA4Data);
    tableC4 = reinterpret_cast<unsigned long>(tableC4Data);
    table130 = reinterpret_cast<unsigned long>(table130Data);

    owner = 0;
    const Color& zero = zeroColor();
    backdropColor = zero;
    enabled = true;
    setName(name);
    owner = parent;

    if (white) {
        static Color whiteColor(whiteValue);
        backdropColor = whiteColor;
    }
}
