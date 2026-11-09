// from server: 49% by colin
struct CRobloxDoc
{
    void* field0;
    CRobloxDoc* init(int arg1, int arg2);
};

extern "C" void* __cdecl sub_0062FEF6(unsigned int size);

CRobloxDoc* CRobloxDoc::init(int arg1, int arg2)
{
    void* p;
    field0 = 0;
    p = sub_0062FEF6(0x14);
    if (p != 0)
    {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)p = (void*)0x791970;
        *(int*)((char*)p + 0xc) = arg1;
    }
    else
    {
        p = 0;
    }
    field0 = p;
    return this;
}
