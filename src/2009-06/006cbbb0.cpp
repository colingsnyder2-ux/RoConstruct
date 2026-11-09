// from server: 100% by tester
struct ResizeTool {
    char pad[0x24];
    void* ptr28;
    char overHandle;
    void onMouseDown(int);
    void findTargetPV(int);
};

void ResizeTool::onMouseDown(int a)
{
    findTargetPV(a);
    void* p = ptr28;
    if (p)
        p = *(void**)((char*)p + 4);
    else
        p = 0;
    overHandle = (p != 0);
    findTargetPV(a);
}
