// from server: 100% by king_originala
typedef void (__thiscall *AssignText)(void *, const char *);
typedef const char *(__thiscall *GetText)(void *);

extern AssignText assignText;
extern GetText getText;
extern char textStorage[4];
extern char otherStorage[4];
extern int savedB;
extern int savedA;
extern int savedC;
extern int savedD;

struct Control {
    void setText(const char *, int);
};

#define SLOT(n) virtual void unused##n();
#define TEN(n) SLOT(n##0) SLOT(n##1) SLOT(n##2) SLOT(n##3) SLOT(n##4) \
               SLOT(n##5) SLOT(n##6) SLOT(n##7) SLOT(n##8) SLOT(n##9)

struct View {
    TEN(0)
    TEN(1)
    TEN(2)
    TEN(3)
    TEN(4)
    TEN(5)
    TEN(6)
    TEN(7)
    TEN(8)
    TEN(9)
    SLOT(100)
    SLOT(101)
    SLOT(102)
    SLOT(103)
    SLOT(104)
    SLOT(105)
    virtual int apply(const char *, int, int, int, int, int);
    virtual int check(const char *, int, int, int, int);
    SLOT(108)
    SLOT(109)
    SLOT(110)
    SLOT(111)
    virtual int prepare(const char *, int, int, int);
    SLOT(113)
    virtual int finish();

    char padding[0x54];
    Control control;

    int update(const char *, int, int, int, int, const char *);
};

#undef TEN
#undef SLOT

int View::update(const char *text, int a, int b, int c, int d,
                 const char *other)
{
    assignText(textStorage, text);
    assignText(otherStorage, other);

    savedB = b;
    savedC = c;
    savedA = a;
    savedD = d;

    if (!prepare(getText(textStorage), b, c, d)) {
        if (!check(getText(textStorage), a, b, c, d))
            return apply(getText(textStorage), a, b, c, d, 1);
    } else {
        control.setText(getText(otherStorage), 1);
        if (!check(getText(textStorage), a, b, c, d))
            return apply(getText(textStorage), a, b, c, d, 1);
    }
    return finish();
}
