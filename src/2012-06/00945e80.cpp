// from server: 39% by atomic.potato
extern "C" void* __stdcall sub_B22648(const char*);

struct AnchorTool
{
    char pad0[0x34];
    int field34;
    char pad1[4];
    char field3c;
    void* method(void* arg);
};

void* AnchorTool::method(void* arg)
{
    if (field34 != 0)
    {
        if (field3c != 0)
        {
            sub_B22648((const char*)0xC006C8);
        }
        else
        {
            sub_B22648((const char*)0xC006B8);
        }
    }
    else
    {
        sub_B22648((const char*)0xC006B8);
    }
    return arg;
}
