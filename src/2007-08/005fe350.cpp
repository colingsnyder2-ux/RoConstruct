// from server: 100% by colin
struct AxisMoveTool {
    char pad0[0x24];
    void* field24;
    char pad28[0x1c];
    unsigned char field44;
    int destroy(int);
};

extern "C" void __fastcall sub_5e0fa0(void* p);

int AxisMoveTool::destroy(int)
{
    if (field44 != 0) {
        sub_5e0fa0(field24);
        field24 = 0;
        field44 = 0;
    }
    void** vtbl = *(void***)this;
    void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))vtbl[9];
    fn(this);
    return 0;
}
