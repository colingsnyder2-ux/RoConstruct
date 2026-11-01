// from server: 100% by king_originala
struct Point
{
    int x;
    int y;
};

extern "C" {
    extern int (__stdcall *ClientToScreen)(void*, Point*);
    extern long (__stdcall *SendMessageA)(void*, unsigned int, unsigned int, long);
}

struct Context
{
    void setPoint(Point);
    void setEnabled(int);
};

struct ThreadState
{
    char padding[0x94];
    Context** context;
};

extern ThreadState* __cdecl getThreadState();

struct BaseControl
{
    char padding[0xD8];
    void onMouse(unsigned int, Point);
};

struct SelectionTree
{
    char padding0[0x20];
    void* window;
    char padding1[0x30];
    BaseControl base;
    int active;

    void* hitTest(Point, unsigned int*);
    void* adjustSelection(void*);
    void onMouse(unsigned int, Point);
};

void SelectionTree::onMouse(unsigned int flags, Point point)
{
    if (active)
    {
        Point screenPoint = point;
        unsigned int hitFlags;

        ClientToScreen(window, &screenPoint);
        (*getThreadState()->context)->setPoint(screenPoint);

        void* item = hitTest(point, &hitFlags);
        if (item)
        {
            if (hitFlags & 0x46)
                item = adjustSelection(item);
            else
                item = 0;
        }

        (*getThreadState()->context)->setEnabled(0);
        SendMessageA(window, 0x110B, 8, (long)item);
        (*getThreadState()->context)->setEnabled(1);
    }

    base.onMouse(flags, point);
}
