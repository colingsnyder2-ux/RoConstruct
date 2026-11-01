// from server: 100% by colin
struct MegaDragger {
    void release();
};

struct GroupDragTool
{
    char pad0[0x20];
    MegaDragger* megaDragger;
    char pad24[0x8];
    bool dragging;
    char pad2d[0x3];

    int func(int);
};

int GroupDragTool::func(int)
{
    if (dragging)
    {
        megaDragger->release();
        dragging = false;
    }
    (*(void (__thiscall**)(GroupDragTool*))(*(int*)this + 0x24))(this);
    return 0;
}
