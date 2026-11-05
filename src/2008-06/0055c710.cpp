// from server: 100% by king_originala
struct String {
    unsigned char data[28];
};

extern void (__thiscall *copyString)(String *, const String *);

struct S {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void finish();

    unsigned char padding[8];
    String text;

    String *get(String *result);
};

String *S::get(String *result)
{
    volatile int state = 0;
    finish();
    copyString(result, &text);
    return result;
}
