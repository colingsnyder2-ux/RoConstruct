// from server: 66% by atomic.potato
extern "C" void sub_00B22648(void*, const char*);

struct WeldTool
{
    WeldTool* f(const char*);
};

WeldTool* WeldTool::f(const char* value)
{
    sub_00B22648(this, "WeldCursor");
    return this;
}
