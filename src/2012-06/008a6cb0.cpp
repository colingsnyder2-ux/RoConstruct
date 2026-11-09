// from server: 66% by atomic.potato
extern "C" void* __cdecl sub_8A6CB0(void*, const char*);

struct ModelSetFrontTool
{
    int f(const char*);
};

int ModelSetFrontTool::f(const char* direction)
{
    sub_8A6CB0((void*)this, "DirectionCursor");
    return (int)this;
}
