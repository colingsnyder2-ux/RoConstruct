// from server: 46% by Intel
struct VPartDragTool {
    void* vftable;
    float field_44;
    float field_48;
    void (__thiscall *vfunc_34)(VPartDragTool*);
    int __thiscall method(void* arg);
};

int __thiscall VPartDragTool::method(void* arg)
{
    short* s = (short*)arg;
    int x = s[4];
    int y = s[5];
    field_44 = (float)x;
    field_48 = (float)y;
    vfunc_34(this);
    return (int)this;
}
