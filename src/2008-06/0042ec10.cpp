// from server: 100% by king_originala
struct Rect {
    int left;
    int top;
    int right;
    int bottom;
};

struct Child {
    char pad[0x20];
    int handle;

    void sub_6a0a4c(int, int, int, int, int);
    int sub_6a0fb0(unsigned int, const Rect *, void *, unsigned int);
    void sub_6a0c38(unsigned int, unsigned int, unsigned int);
};

struct CWrapperView {
    char pad[0x58];
    Child child;

    int sub_6a0800(unsigned int, unsigned int, unsigned int, int *);
    int func_42ec10(unsigned int, unsigned int, unsigned int, int *);
};

int CWrapperView::func_42ec10(unsigned int message, unsigned int wparam,
                            unsigned int lparam, int *result)
{
    int handled = sub_6a0800(message, wparam, lparam, result);
    if (handled && *result)
        return 1;

    switch (message) {
    case 1:
        {
            Rect rect = { 0, 0, 100, 100 };
            if (!child.sub_6a0fb0(0x56000000, &rect, this, 0)) {
                *result = -1;
                return 1;
            }
            child.sub_6a0c38(0, 0x200, 0x20);
        }
        return 1;

    case 5:
        if (child.handle)
            child.sub_6a0a4c(0, 0, (unsigned short)lparam, lparam >> 16, 1);
        return 1;
    }
    return handled;
}
