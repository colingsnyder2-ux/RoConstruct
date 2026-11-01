// from server: 100% by king_originala
struct Interface {
    void update();
};

struct CRobloxWnd {
    char padding0[0x70];
    int active;
    char padding1[0x10];
    Interface* interfacePtr;

    void start();
    void refresh();
    void finish();
    void handle(int state);
};

void CRobloxWnd::handle(int state)
{
    switch (state) {
    case 0:
        start();
        refresh();
        break;
    case 1:
        if (active && interfacePtr)
            interfacePtr->update();
        break;
    }
    finish();
}
