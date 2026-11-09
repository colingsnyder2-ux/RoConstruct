// from server: 100% by colin
struct CXTPReportSelectedRows
{
    int f();
};

struct Sub
{
    void g();
};

extern "C" void __stdcall sub_73833a();
extern "C" void __stdcall sub_663d90();

int CXTPReportSelectedRows::f()
{
    sub_73833a();
    *(int*)this = 0x7c968c;
    ((Sub*)((char*)this + 0x20))->g();
    *(int*)((char*)this + 0x34) = 0;
    *(int*)((char*)this + 0x38) = 0;
    return (int)this;
}
