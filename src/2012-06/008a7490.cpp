// from server: 71% by Intel
struct std_string
{
    std_string(const char*);
};

extern "C" void __stdcall G1_func_00B22648(std_string*);

struct DropperTool
{
    int func_008A7490(int);
};

int DropperTool::func_008A7490(int arg)
{
    std_string str("DropperCursor");
    G1_func_00B22648(&str);
    return arg;
}
