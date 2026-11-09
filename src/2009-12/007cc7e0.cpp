// from server: 100% by atomic.potato
extern "C" void __stdcall func_007dbdb0();
extern "C" void __cdecl func_007f385a(void*);

struct RBX_GroupDropTool
{
    void* vtable0;
    void* vtable4;
    char pad[0x30];
    void* vtable38;
    void* destroy(char);
};

void* RBX_GroupDropTool::destroy(char flag)
{
    vtable0 = (void*)0x9ee98c;
    vtable4 = (void*)0x9ee974;
    vtable38 = (void*)0x9ee96c;
    func_007dbdb0();
    if (flag & 1)
        func_007f385a(this);
    return this;
}
