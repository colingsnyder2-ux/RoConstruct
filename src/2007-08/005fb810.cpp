// from server: 100% by tajop
struct InletTool {
    char pad[0x18];
    void* field18;
    void construct(void* workspace);
};

extern "C" void* __cdecl func_00561b10(void* a);

struct Ret {
    void method_0058c810(int);
};

struct Inner {
    void method_00573d60();
    void method_00573d80();
};

struct MouseCmd {
    void method_005b9520();
    void method_005b9270(int);
    Inner* inner;
};

void InletTool::construct(void* workspace)
{
    MouseCmd* cmd = (MouseCmd*)workspace;
    cmd->inner->method_00573d60();
    cmd->method_005b9520();
    cmd->method_005b9270(4);
    cmd->inner->method_00573d80();
    ((Ret*)func_00561b10(field18))->method_0058c810(8);
}


