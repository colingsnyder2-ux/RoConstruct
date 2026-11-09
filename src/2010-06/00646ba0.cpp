// from server: 100% by atomic.potato
struct TypeInfo
{
    bool operator==(const TypeInfo& other) const;
};

struct S
{
    bool f();
};

extern "C" TypeInfo* sub_007a93c6(int value);
extern "C" bool (__thiscall *g_type_info_equal)(TypeInfo*, const TypeInfo&);
extern TypeInfo g_axis_move_tool_type;

bool S::f()
{
    int* p = *(int**)((char*)this + 12);
    int value = *(int*)((char*)p + 0xaa0);
    int result = *(int*)((char*)value + 0x1b4);
    if (result)
    {
        TypeInfo* info = sub_007a93c6(result);
        return g_type_info_equal(&g_axis_move_tool_type, *info);
    }
    return false;
}
