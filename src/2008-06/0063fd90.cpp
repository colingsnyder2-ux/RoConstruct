// from server: 100% by king_originala
struct String;

typedef void (__thiscall *StringConstructor)(String *, const char *);
extern StringConstructor constructString;

struct CloneTool {
    char padding[28];
    int active;
    String *cursor(String *result);
};

String *CloneTool::cursor(String *result)
{
    volatile int state = 0;
    if (active)
        constructString(result, "CloneOverCursor");
    else
        constructString(result, "CloneCursor");
    return result;
}
