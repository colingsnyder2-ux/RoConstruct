// from server: 100% by king_originala
struct ChildWindow
{
    void __thiscall MoveWindow(int x, int y, int width, int height, int repaint);
};

struct CMultiPlayerPane
{
    char reserved[0x54];
    ChildWindow* child;

    void __thiscall UpdateLayout();
    void __thiscall OnSize(unsigned int type, int width, int height);
};

void CMultiPlayerPane::OnSize(unsigned int type, int width, int height)
{
    if (type != 1 && child)
        child->MoveWindow(0, 0, width, height, 1);

    UpdateLayout();
}
