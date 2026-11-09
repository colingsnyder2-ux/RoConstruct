// from server: 100% by king_originala
struct String {
    char data[28];
};

struct Result {
    String text;
    int value;
};

extern void (__thiscall *copyString)(String *, const String *);

struct S {
    char padding[0x144];
    Result member;

    void update();
    Result f();
};

Result S::f()
{
    volatile int state = 0;
    update();

    Result *source = &member;
    Result result;
    copyString(&result.text, &source->text);
    result.value = source->value;
    return result;
}
