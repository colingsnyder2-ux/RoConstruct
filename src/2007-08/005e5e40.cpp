// from server: 100% by colin
struct RBX_NullTool {
    RBX_NullTool* destroy(char);
};

extern "C" void __cdecl func_005e3d50();
extern "C" void __cdecl func_0062fc62(void*);

RBX_NullTool* RBX_NullTool::destroy(char flags)
{
    *(int*)this = 0x7bd224;
    *(int*)((char*)this + 4) = 0x7bd20c;
    func_005e3d50();
    if (flags & 1) {
        func_0062fc62(this);
    }
    return this;
}
