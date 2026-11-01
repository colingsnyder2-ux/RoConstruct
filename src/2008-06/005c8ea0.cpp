// from server: 100% by king_originala
struct String;

extern void (__thiscall *destroyString)(String *);
extern String *(__thiscall *assignString)(String *, const String *);

struct String {
    char storage[28];
    ~String();
};

__forceinline String::~String()
{
    destroyString(this);
}

extern String __cdecl formatValue(unsigned int);

struct LaserTool {
    char padding[0x130];
    double value;
    String label;

    void setValue(unsigned int);
    void applyValue(const String &, unsigned int);
};

__forceinline void LaserTool::applyValue(const String &text, unsigned int n)
{
    value = n;
    assignString(&label, &text);
}

void LaserTool::setValue(unsigned int n)
{
    applyValue(formatValue(n), n);
}
