// from server: 54% by atomic.potato
struct CXTPDockingPaneManager {
    int pad0;
    int pad4;
    int pad8;
    int padc;
    void sub_9c6950();
    void sub_9c6410(int, int, int, int);
    int func(int, int, int, int, int, int);
};

int CXTPDockingPaneManager::func(int a, int b, int c, int d, int e, int f) {
    *(int*)this = a;
    *(int*)((char*)this + 4) = b;
    *(int*)((char*)this + 8) = c;
    *(int*)((char*)this + 12) = d;
    sub_9c6950();
    int r;
    if (e != 0)
        r = 9;
    else
        r = (f != 0) ? 1 : 5;
    sub_9c6410(r, 0, 0, 0);
    return 1;
}
