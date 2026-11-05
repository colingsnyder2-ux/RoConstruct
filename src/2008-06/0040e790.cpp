// from server: 100% by king_originala
struct P {};

extern int (__thiscall *check)(P*, const char*);
extern void* (__thiscall *obtain)(P*, int, int, int, int, int);

static const char authoring[11] = {
    0, 0, '\xf1', 'h', '\xe3', '\x88',
    '\xb5', '\xf8', '\xe4', '>', 'A'
};

struct CBrowserView {
    char padding[0x2cc];
    P p;

    void update();
    void apply(void*);
};

void CBrowserView::update()
{
    P* object = &p;
    if (check(object, authoring))
        apply(obtain(object, 0, 0, 0, 0, 0));
}
