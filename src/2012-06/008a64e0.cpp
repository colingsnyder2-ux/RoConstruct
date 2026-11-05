// from server: 58% by atomic.potato
extern "C" void* __stdcall sub_00B22648(void*, const char*);

struct UniversalTool
{
    UniversalTool(const char*);
};

UniversalTool::UniversalTool(const char* value)
{
    sub_00B22648((void*)0x00BDF4DC, value);
}
