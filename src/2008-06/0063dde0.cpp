// from server: 100% by colin
struct String;

typedef String* (__thiscall *StringConstructor)(String*, const char*);
extern StringConstructor constructString;

struct S {
    char padding0[0x1c];
    int active;
    char padding1[4];
    unsigned char anchored;

    String* f(String* result);
};

String* S::f(String* result)
{
    volatile int temporary = 0;
    if (active) {
        if (anchored) {
            constructString(result, "UnAnchorCursor");
            return result;
        }
        constructString(result, "AnchorCursor");
        return result;
    }
    constructString(result, "AnchorCursor");
    return result;
}
