// from server: 100% by king_originala
extern "C" int (__stdcall *InvalidateRect)(void *, const void *, int);

struct CBrowserView {
    char reserved0[0x13c];
    void *window;
    char reserved1[0x188];
    bool flag2;
    bool flag1;

    void baseNotify(int code, int value);
    void notify(int code, int value);
};

void CBrowserView::notify(int code, int value)
{
    baseNotify(code, value);

    switch (code) {
    case -1:
        InvalidateRect(window, 0, 1);
        break;
    case 1:
        flag1 = value != 0;
        break;
    case 2:
        flag2 = value != 0;
        break;
    }
}
