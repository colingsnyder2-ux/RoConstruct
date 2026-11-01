// from server: 100% by king_originala
struct Target {
    void perform(int);
};

struct CRobloxWnd {
    char reserved[0x84];
    Target *target;

    void previous(int);
    void f(int);
};

void CRobloxWnd::f(int value)
{
    previous(value);
    if (target)
        target->perform(1);
}
