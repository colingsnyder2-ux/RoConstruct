// from server: 54% by atomic.potato
struct MoveResizeJoinTool
{
    int f(const void*);
};

extern "C" void* __stdcall sub_8A5230(void*, const void*);

int MoveResizeJoinTool::f(const void* value)
{
    sub_8A5230((char*)this + 200, value);
    return (int)this;
}
