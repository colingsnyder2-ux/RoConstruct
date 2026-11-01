// from server: 100% by king_originala
struct String;

extern void (__thiscall *constructString)(String *, const char *);

struct S {
    char padding[0x34];
    unsigned char rotate;
    String *f(String *result);
};

String *S::f(String *result)
{
    volatile int state = 0;
    const char *cursor = rotate ? "GrabRotateCursor" : "DragCursor";
    constructString(result, cursor);
    return result;
}
