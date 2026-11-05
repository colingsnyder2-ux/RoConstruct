// from server: 49% by colin
extern "C" void* __cdecl func_0062fef6(unsigned int size);

struct CRobloxReportDocView
{
    void* field_0;
    CRobloxReportDocView* ctor(void* arg1, void* arg2);
};

CRobloxReportDocView* CRobloxReportDocView::ctor(void* arg1, void* arg2)
{
    void* p;
    this->field_0 = 0;
    p = func_0062fef6(0x14);
    if (p != 0)
    {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)p = (void*)0x791eb4;
        *(void**)((char*)p + 0xc) = arg1;
    }
    else
    {
        p = 0;
    }
    this->field_0 = p;
    return this;
}
