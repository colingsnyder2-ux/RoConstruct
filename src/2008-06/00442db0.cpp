// from server: 100% by colin
struct CPropGrid
{
    void* vtable;
    void* field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    char field1C;
    char field1D;
    int field20;
    void destroy();
};

extern "C" int (__stdcall *DeleteObject)(void*);

void CPropGrid::destroy()
{
    void* p = field4;
    vtable = (void*)0x8157c0;
    if (p != 0)
    {
        field4 = 0;
        field8 = 0;
        fieldC = 0;
        field10 = 0;
        field18 = 0;
        field14 = 0;
        field20 = -1;
        field1D = 0;
        field1C = 0;
        DeleteObject(p);
    }
}
