// from server: 66% by atomic.potato
extern "C" void* __cdecl sub_008A72D0(void*, const char*);

struct MaterialTool
{
    MaterialTool(void*);
};

MaterialTool::MaterialTool(void* value)
{
    sub_008A72D0(this, "MaterialCursor");
}
