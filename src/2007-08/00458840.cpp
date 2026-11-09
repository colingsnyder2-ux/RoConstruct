// from server: 49% by colin
struct CRobloxWnd
{
    void* field0;
    CRobloxWnd* construct(void* a, void* b);
};

extern "C" void* __cdecl sub_62FEF6(unsigned int size);

CRobloxWnd* CRobloxWnd::construct(void* a, void* b)
{
    void* mem;
    this->field0 = 0;
    mem = sub_62FEF6(0x14);
    if (mem)
    {
        *(int*)((char*)mem + 4) = 1;
        *(int*)((char*)mem + 8) = 1;
        *(void**)mem = (void*)0x793310;
        *(void**)((char*)mem + 0xc) = a;
    }
    else
    {
        mem = 0;
    }
    this->field0 = mem;
    return this;
}
