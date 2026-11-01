// from server: 100% by king_originala
struct Rect {
    long left, top, right, bottom;
};

extern "C" int (__stdcall *InvalidateRect)(void*, const Rect*, int);

struct Tree {
    char padding[0x20];
    void* window;
    int getRect(unsigned int item, Rect* rect, int textOnly);
};

struct Selection {
    char padding0[0x54];
    unsigned char flags;
    char padding1[3];
    Tree* tree;
    char padding2[0x24];
    unsigned int item;
    void f();
};

void Selection::f()
{
    if (flags & 1) {
        if (item != 0 && item != 0xffff0000U) {
            Rect rect;
            if (tree->getRect(item, &rect, 0))
                InvalidateRect(tree->window, &rect, 1);
        }
        flags &= 0xfe;
    }
}
