// from server: 100% by king_originala
struct String {
    char storage[28];
};

extern String& (__thiscall *assignString)(String*, const char*);
extern const char trueText[];
extern const char falseText[];

struct LaserTool {
    char padding[0x130];
    double value;
    String text;

    void setValue(const bool* state);
};

void LaserTool::setValue(const bool* state)
{
    assignString(&text, *state ? trueText : falseText);
    value = static_cast<int>(*state != 0);
}
