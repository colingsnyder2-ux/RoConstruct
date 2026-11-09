// from server: 100% by colin
struct SurfaceTool {
    void sub_00573d60();
    void sub_00573d80();
    void sub_005b9270(int);
    void sub_005b92c0(int);
    void sub_005b9380(float);
    void sub_005b9450(float);
};

struct RightMotorTool {
    void func_005fb280(SurfaceTool*);
};

extern float g_7bcf14;
extern float g_797eb0;

void RightMotorTool::func_005fb280(SurfaceTool* a)
{
    SurfaceTool* p = *(SurfaceTool**)a;
    p->sub_00573d60();
    a->sub_005b9270(7);
    a->sub_005b92c0(2);
    a->sub_005b9380(g_7bcf14);
    a->sub_005b9450(g_797eb0);
    (*(SurfaceTool**)a)->sub_00573d80();
}
