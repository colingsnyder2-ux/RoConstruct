// from server: 94% by atomic.potato
extern "C" void __cdecl func_007dbd10(int);

struct GroupDropTool
{
    virtual int vfunc_38();
    int func_007cc720(int);
};

int GroupDropTool::func_007cc720(int value)
{
    func_007dbd10(value);
    ((int (__thiscall *)(GroupDropTool *))(*(int **)(this))[0x38 / 4])(this);
    return 0;
}
