// from server: 56% by atomic.potato
extern "C" void* __cdecl sub_00B22648(void*, const char*);

struct HingeTool
{
    HingeTool(const char*);
};

HingeTool::HingeTool(const char* arg)
{
    sub_00B22648((char*)this, arg);
}
