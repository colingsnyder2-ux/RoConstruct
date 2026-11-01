// from server: 100% by king_originala
struct Point {
    int x;
    int y;
};

extern "C" int (__stdcall *ClientToScreen)(void *, Point *);

struct Tree {
    void OnButton(unsigned int flags, Point point);
};

struct S {
    char padding0[0x20];
    void *window;
    char padding1[0x30];
    Tree tree;

    void OnButton(unsigned int flags, Point point);
    void ShowMenu(int x, int y);
};

void S::OnButton(unsigned int flags, Point point)
{
    tree.OnButton(flags, point);
    ClientToScreen(window, &point);
    ShowMenu(point.x, point.y);
}
