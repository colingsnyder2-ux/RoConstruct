// from server: 100% by colin
struct LockTool {
    LockTool* construct(void* workspace);
};

LockTool* LockTool::construct(void* workspace)
{
    extern void __stdcall base_construct(void* workspace);
    base_construct(workspace);
    *(int*)((char*)this + 0) = 0x7c2484;
    *(int*)((char*)this + 4) = 0x7c2468;
    *(volatile int*)((char*)this + 0x20) = 0;
    *(int*)((char*)this + 0x24) = 0;
    return this;
}
