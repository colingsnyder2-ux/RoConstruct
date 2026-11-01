// from server: 100% by king_originala
struct POINT
{
    int x, y;
};

struct RECT
{
    int left, top, right, bottom;

    RECT(int l, int t, int r, int b)
        : left(l), top(t), right(r), bottom(b) {}
};

struct Parent
{
    int getEnabled();
};

struct S
{
    typedef void (__thiscall *VirtualFunction)(S*);

    VirtualFunction* vtable;
    char padding0[0x98];
    int enabled;
    char padding1[0xBC];
    Parent* parent;
    char padding2[0x18];
    int selected;

    int getEnabled()
    {
        if (enabled != -1 || !parent)
            return enabled;
        return parent->getEnabled();
    }

    int hitTest(POINT point);
    void execute(RECT rect);
    void click(int keyboard, POINT point);
};

void S::click(int keyboard, POINT point)
{
    if (getEnabled())
    {
        int index = hitTest(point);
        if (index != -1)
        {
            selected = index;
            if (!keyboard)
                execute(RECT(0, 0, 0, 0));
            else
                vtable[38](this);
            selected = -1;
        }
    }
}
