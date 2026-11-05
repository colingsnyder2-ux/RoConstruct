// from server: 65% by atomic.potato
extern "C" void* sub_00B22648(void*, const char*);

struct InletTool
{
    int f(void*);
};

int InletTool::f(void* value)
{
    char buffer[4];
    *(int*)buffer = 0;
    sub_00B22648(buffer, "InletCursor");
    return (int)value;
}
