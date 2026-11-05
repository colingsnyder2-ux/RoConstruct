// from server: 46% by colin
struct VDHTMLWindow_SignalDesc
{
    void* ptr;
    VDHTMLWindow_SignalDesc(void* arg);
};

extern "C" void* __cdecl sub_62FEF6(unsigned int size);

VDHTMLWindow_SignalDesc::VDHTMLWindow_SignalDesc(void* arg)
{
    ptr = 0;
    void* mem = sub_62FEF6(0x14);
    if (mem)
    {
        *(int*)((char*)mem + 4) = 1;
        *(int*)((char*)mem + 8) = 1;
        *(void**)mem = (void*)0x787a68;
        *(void**)((char*)mem + 0xc) = arg;
    }
    else
    {
        mem = 0;
    }
    ptr = mem;
}
