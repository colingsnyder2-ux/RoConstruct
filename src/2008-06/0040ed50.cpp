// from server: 100% by king_originala
struct Control {
    char data;
};

extern int (__thiscall *lookup)(Control*, const char*);
extern int (__thiscall *query)(Control*, int, int, int, int, int);

static const char key[11] = {
    0, 0, (char)0xf1, 0x68, (char)0xe3, (char)0x88,
    (char)0xb5, (char)0xf8, (char)0xe4, 0x3e, 0x41
};

struct CBrowserView {
    char padding0[0x54];
    CBrowserView* link;
    char padding1[0x2cc - 0x58];
    Control control;

    void initialize();
    void apply(int value);
    void invoke();
};

void CBrowserView::invoke() {
    initialize();

    if (link)
        link->link = this;

    if (lookup(&control, key))
        apply(query(&control, 0, 0, 0, 0, 0));
}
