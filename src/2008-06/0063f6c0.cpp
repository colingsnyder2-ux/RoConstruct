// from server: 100% by king_originala
typedef void (__thiscall *StringConstructor)(void *, const char *);
extern StringConstructor constructString;

struct HammerTool {
    char padding[0x1c];
    int over;
    void *cursor(void *result);
};

void *HammerTool::cursor(void *result)
{
    volatile int state = 0;
    const char *text = over ? "HammerOverCursor" : "HammerCursor";
    constructString(result, text);
    return result;
}
