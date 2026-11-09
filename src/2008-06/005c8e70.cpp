// from server: 100% by king_originala
struct String;

extern void (__thiscall *copyString)(String *, const String *);

struct LaserTool {
    String *getValue(String *result);
};

String *LaserTool::getValue(String *result)
{
    volatile int state = 0;
    (*(void (__thiscall **)(LaserTool *))(*(char **)this + 0x40))(this);
    copyString(result, (const String *)((char *)this + 0x138));
    return result;
}
