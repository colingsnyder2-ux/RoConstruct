// from server: 40% by atomic.potato
struct AxisMoveTool
{
    int f(void*);
};

extern "C" void* basic_string_copy(void*, const void*);

int AxisMoveTool::f(void* value)
{
    basic_string_copy((char*)this + 0x3c, value);
    return (int)this;
}
