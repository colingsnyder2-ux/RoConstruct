// from server: 49% by colin
struct CChildFrame
{
    void* field0;
    CChildFrame(void* arg1, void* arg2);
};

extern "C" void* __cdecl sub_62fef6(unsigned int size);

CChildFrame::CChildFrame(void* arg1, void* arg2)
{
    field0 = 0;
    void* p = sub_62fef6(0x14);
    if (p)
    {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)((char*)p + 0) = (void*)0x786acc;
        *(void**)((char*)p + 0xc) = arg1;
    }
    else
    {
        p = 0;
    }
    field0 = p;
}
