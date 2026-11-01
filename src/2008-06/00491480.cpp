// from server: 100% by king_originala
struct String {
    char storage[28];
};

typedef void (__thiscall *StringConstructor)(String *, const char *);
extern StringConstructor constructString;
extern const char authoring[];

struct S {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();

    String *f(String *result, int unused);
};

String *S::f(String *result, int unused)
{
    volatile int local = 0;
    slot6();
    constructString(result, authoring);
    return result;
}
