// from server: 66% by atomic.potato
extern "C" void* __cdecl sub_5BDB0(void*, const char*);

struct FlatTool
{
    FlatTool(const char*);
};

FlatTool::FlatTool(const char* name)
{
    sub_5BDB0(this, "FlatCursor");
}
