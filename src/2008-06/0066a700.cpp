// from server: 100% by king_originala
struct String;

extern void (__thiscall *constructString)(String *, const char *);

struct S {
    char padding[40];
    bool rotating;
    String *f(String *result);
};

String *S::f(String *result)
{
    volatile int state = 0;
    const char *cursor = rotating ? "GrabRotateCursor" : "DragCursor";
    constructString(result, cursor);
    return result;
}
