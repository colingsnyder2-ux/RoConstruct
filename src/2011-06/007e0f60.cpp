// from server: 65% by atomic.potato
extern "C" void* (__cdecl *sub_a404c4)(void*, const char*);

struct HammerTool
{
    void* f(const char*);
};

void* HammerTool::f(const char* arg)
{
    const char* name;
    if (*(int*)((char*)this + 0x20) != 0)
        name = "HammerOverCursor";
    else
        name = "HammerCursor";
    sub_a404c4((void*)arg, name);
    return (void*)arg;
}
