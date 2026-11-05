// from server: 100% by king_originala
struct CRobloxView {
    char padding[0x1d8];
    int state;

    void setState(bool enabled, int notify);
    void toggleState();
};

void CRobloxView::toggleState()
{
    setState(state == 0, 1);
}
