// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct String;

typedef void (__thiscall *StringConstructor)(String *, const char *);
extern StringConstructor constructString;

struct S {
    char padding[28];
    unsigned char dragging;
    String *f(String *result);
};

String *S::f(String *result)
{
    volatile int unused = 0;
    const char *cursor = dragging ? "DragCursor" : "ArrowCursor";
    constructString(result, cursor);
    return result;
}